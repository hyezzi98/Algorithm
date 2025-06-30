n, m = map(int,input().split())

# 양방향 그래프 생성
graph = [[] for _ in range(n)]
visited = [0] * n
result = 0

for _ in range(m):
    a, b = map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)

def dfs(node, depth):
    global result
    visited[node] = 1
    
    # basis part
    if depth == 4:
        result = 1
        return

    # inductive part
    for i in graph[node]:
        if not visited[i]:
            dfs(i, depth + 1)
    # 방문한 노드 초기화
    visited[node] = 0

for i in range(n):
    dfs(i, 0)
    if result == 1:
        break
    
print(result)