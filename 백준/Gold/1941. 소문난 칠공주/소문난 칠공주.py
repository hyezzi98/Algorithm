from collections import deque
from itertools import combinations
array = [[] for _ in range(5)]
result = 0
for i in range(5):
   array[i] = list(input())

# 1. 7칸의 조합 만들기
positions = [(i, j) for i in range(5) for j in range(5)]
comb = list(combinations(positions, 7))

# 3. 연결되었는지 확인하기
def is_connected(group):
    group_set = set(group)
    stack = [group[0]]
    visited = {group[0]}

    while stack:
        y, x = stack.pop()
        for dy, dx in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            ny = y + dy
            nx = x + dx
            if (ny, nx) in group_set and (ny, nx) not in visited:
                visited.add((ny, nx))
                stack.append((ny, nx))
    return len(visited) == 7

# 2. 만든 조합에서 s의 개수 세기
for group in comb:
    cnt = 0
    for y, x in group:
        if array[y][x] == 'S':
            cnt += 1
    if cnt >= 4:
        if is_connected(group):
            result += 1

print(result)