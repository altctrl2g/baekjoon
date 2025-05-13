import os
import re
import requests
import shutil
import subprocess

# 백준 문제 정보 가져오기
def get_problem_info(problem_id):
    url = f"https://solved.ac/api/v3/problem/show?problemId={problem_id}"
    try:
        res = requests.get(url)
        if res.status_code == 200:
            data = res.json()
            title = data['titleKo']
            level = data['level']
            return title, level_map[level]
    except Exception as e:
        print(f"[!] 예외 발생: {problem_id} - {e}")
    return None, None

# 난이도 숫자 => 문자열 매핑
level_map = {
    0: 'Unrated',
    1: 'Bronze 5', 2: 'Bronze 4', 3: 'Bronze 3', 4: 'Bronze 2', 5: 'Bronze 1',
    6: 'Silver 5', 7: 'Silver 4', 8: 'Silver 3', 9: 'Silver 2', 10: 'Silver 1',
    11: 'Gold 5', 12: 'Gold 4', 13: 'Gold 3', 14: 'Gold 2', 15: 'Gold 1',
    16: 'Platinum 5', 17: 'Platinum 4', 18: 'Platinum 3', 19: 'Platinum 2', 20: 'Platinum 1',
    21: 'Diamond 5', 22: 'Diamond 4', 23: 'Diamond 3', 24: 'Diamond 2', 25: 'Diamond 1',
}

# .cpp 파일 정리 및 정보 수집
def organize_cpp_files():
    cpp_files = [f for f in os.listdir('.') if re.fullmatch(r'\d+\.cpp', f)]
    moved = []
    for file in cpp_files:
        problem_id = int(file.replace(".cpp", ""))
        title, level = get_problem_info(problem_id)
        if not title or not level:
            continue
        tier, sublevel = level.split()
        dest_dir = os.path.join(tier)
        os.makedirs(dest_dir, exist_ok=True)
        new_path = os.path.join(dest_dir, file)
        if not os.path.exists(new_path):
            shutil.move(file, new_path)
            moved.append((problem_id, title, tier, level, new_path))
    return moved

# 티어별 README에 추가
def update_sub_readmes(entries):
    readmes = {}
    for pid, title, tier, level, path in entries:
        readme_file = f"README_{tier}.md"
        if readme_file not in readmes:
            if os.path.exists(readme_file):
                with open(readme_file, 'r', encoding='utf-8') as f:
                    lines = f.readlines()
            else:
                lines = [f"# 🏅 {tier} 문제 목록\n\n"]
                for i in range(1, 6):
                    lines.append(f"## {tier} {i}\n\n| 번호 | 제목 | 문제링크 | 코드 |\n|------|------|-----------|------|\n")
            readmes[readme_file] = lines

        lines = readmes[readme_file]
        section = f"## {level}"
        idx = next((i for i, line in enumerate(lines) if line.strip() == section), -1)
        if idx == -1:
            continue

        table_start = idx + 2
        for i in range(table_start, len(lines)):
            if not lines[i].startswith('|'):
                break
            if re.match(rf"\| {pid} ", lines[i]):
                break
        else:
            link = f"https://www.acmicpc.net/problem/{pid}"
            line = f"| {pid} | {title} | [문제]({link}) | [코드](./{path.replace('\\', '/')}) |\n"
            lines.insert(table_start, line)

    for fname, content in readmes.items():
        with open(fname, 'w', encoding='utf-8') as f:
            f.writelines(content)
        print(f"[+] {fname} 업데이트 완료")

# 메인 README 생성 또는 갱신
def update_main_readme():
    with open("README.md", "w", encoding='utf-8') as f:
        f.write("""# 📘 Baekjoon 문제풀이 정리\n\n## 난이도별 문제 목록\n\n- 🥉 [Bronze](./README_Bronze.md)\n- 🥈 [Silver](./README_Silver.md)\n- 🥇 [Gold](./README_Gold.md)\n\n자동 업데이트됨.""")
    print("[*] 메인 README.md 생성 완료")

# 자동 Git 커밋 및 푸시
def git_commit_push(entries):
    try:
        subprocess.run(["git", "add", "."], check=True)
        result = subprocess.run(["git", "status", "--porcelain"], capture_output=True, text=True)
        if not result.stdout.strip():
            print("[*] 커밋할 변경사항 없음. 스킵.")
            return

        if len(entries) == 1:
            pid, title, *_ = entries[0]
            msg = f"Add {pid} {title}"
        else:
            msg = f"Add {len(entries)} new problems"

        subprocess.run(["git", "commit", "-m", msg], check=True)
        subprocess.run(["git", "push"], check=True)
        print(f"[✔] Git 커밋 & 푸시 완료: {msg}")

    except subprocess.CalledProcessError as e:
        print(f"[!] Git 명령 실패: {e}")

if __name__ == '__main__':
    entries = organize_cpp_files()
    if entries:
        update_sub_readmes(entries)
        update_main_readme()
        git_commit_push(entries)
    else:
        print("[*] 새로 추가된 .cpp 파일 없음")
