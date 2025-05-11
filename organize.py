import os
import shutil
import re
import subprocess
import requests

# 난이도 매핑
level_map = {
    0: 'Unrated',
    1: 'Bronze 5', 2: 'Bronze 4', 3: 'Bronze 3', 4: 'Bronze 2', 5: 'Bronze 1',
    6: 'Silver 5', 7: 'Silver 4', 8: 'Silver 3', 9: 'Silver 2', 10: 'Silver 1',
    11: 'Gold 5', 12: 'Gold 4', 13: 'Gold 3', 14: 'Gold 2', 15: 'Gold 1',
    16: 'Platinum 5', 17: 'Platinum 4', 18: 'Platinum 3', 19: 'Platinum 2', 20: 'Platinum 1',
    21: 'Diamond 5', 22: 'Diamond 4', 23: 'Diamond 3', 24: 'Diamond 2', 25: 'Diamond 1',
}

def get_problem_info(problem_id, cache):
    if problem_id in cache:
        return cache[problem_id]

    url = f"https://solved.ac/api/v3/problem/show?problemId={problem_id}"
    try:
        res = requests.get(url)
        if res.status_code == 200:
            data = res.json()
            level = level_map.get(data['level'], 'Unknown')
            title = data['titleKo']
            cache[problem_id] = (level, title)
            return level, title
    except Exception as e:
        print(f"문제 {problem_id} 불러오기 실패: {e}")
    return 'Unknown', 'Unknown'

def organize_cpp_files_and_generate_readme():
    entries = []
    moved_problems = []
    info_cache = {}

    # 1. 루트 디렉토리의 cpp 파일 정리
    root_files = [f for f in os.listdir() if f.endswith(".cpp") and re.match(r"^\d+\.cpp$", f)]
    for file in root_files:
        problem_id = file.split('.')[0]

        level, title = get_problem_info(problem_id, info_cache)
        tier = level.split()[0] if level != 'Unknown' else 'Unrated'

        os.makedirs(tier, exist_ok=True)
        dest_path = os.path.join(tier, file)

        if not os.path.exists(dest_path):
            shutil.move(file, dest_path)
            moved_problems.append((int(problem_id), title, level, tier, file))

    # 2. README는 이동된 문제만 반영
    moved_problems.sort()

    with open("README.md", "w", encoding='utf-8') as f:
        f.write("# 📘 Baekjoon 문제풀이 정리\n\n")
        f.write("| 번호 | 제목 | 난이도 | 문제링크 | 코드 |\n")
        f.write("|------|------|--------|-----------|------|\n")
        for pid, title, level, tier, file in moved_problems:
            boj_link = f"https://www.acmicpc.net/problem/{pid}"
            code_link = f"./{tier}/{file}"
            f.write(f"| {pid} | {title} | {level} | [문제]({boj_link}) | [코드]({code_link}) |\n")

    return [(str(pid), title) for pid, title, *_ in moved_problems]

def git_commit_and_push(moved_problems):
    subprocess.run(["git", "add", "."])

    if len(moved_problems) == 0:
        print("📂 이동된 파일 없음. 푸시 생략.")
        return

    if len(moved_problems) == 1:
        msg = f"Add: BOJ {moved_problems[0][0]} {moved_problems[0][1]}"
    elif 2 <= len(moved_problems) <= 3:
        msg = "Add: BOJ " + ", ".join([f"{pid} {title}" for pid, title in moved_problems])
    else:
        msg = f"Add: BOJ 문제 {len(moved_problems)}개 업로드"

    subprocess.run(["git", "commit", "-m", msg])
    subprocess.run(["git", "push"])
    print("🚀 GitHub 푸시 완료!")

if __name__ == "__main__":
    moved_problems = organize_cpp_files_and_generate_readme()
    git_commit_and_push(moved_problems)
