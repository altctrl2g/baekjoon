import os
import re
import json
import shutil
import requests
import subprocess
from typing import Dict, List, Tuple

# 난이도 매핑
level_map = {
    0: 'Unrated',
    1: 'Bronze 5', 2: 'Bronze 4', 3: 'Bronze 3', 4: 'Bronze 2', 5: 'Bronze 1',
    6: 'Silver 5', 7: 'Silver 4', 8: 'Silver 3', 9: 'Silver 2', 10: 'Silver 1',
    11: 'Gold 5', 12: 'Gold 4', 13: 'Gold 3', 14: 'Gold 2', 15: 'Gold 1',
    16: 'Platinum 5', 17: 'Platinum 4', 18: 'Platinum 3', 19: 'Platinum 2', 20: 'Platinum 1',
    21: 'Diamond 5', 22: 'Diamond 4', 23: 'Diamond 3', 24: 'Diamond 2', 25: 'Diamond 1',
}

def get_problem_info(problem_id: str, cache: Dict[str, Tuple[str, str]]) -> Tuple[str, str]:
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

def generate_readme_for_all() -> None:
    cache = {}
    all_problems = []

    for tier in os.listdir():
        if not os.path.isdir(tier): continue
        for file in os.listdir(tier):
            if file.endswith(".cpp") and re.match(r"^\d+\.cpp$", file):
                pid = file.split('.')[0]
                level, title = get_problem_info(pid, cache)
                all_problems.append((int(pid), title, level, tier, file))

    all_problems.sort()

    with open("README.md", "w", encoding='utf-8') as f:
        f.write("# 📘 Baekjoon 문제풀이 정리\n\n")
        f.write("| 번호 | 제목 | 난이도 | 문제링크 | 코드 |\n")
        f.write("|------|------|--------|-----------|------|\n")
        for pid, title, level, tier, file in all_problems:
            boj_link = f"https://www.acmicpc.net/problem/{pid}"
            code_link = f"./{tier}/{file}"
            f.write(f"| {pid} | {title} | {level} | [문제]({boj_link}) | [코드]({code_link}) |\n")

generate_readme_for_all()
