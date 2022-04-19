from collections import deque
import sys
sys.setrecursionlimit(100000)
cnt = 1
n = int(input())
g = [[0]]
vis = [[False] * (n + 1) for i in range(n + 1)]
dis = [[int(1e9)] * (n + 1) for i in range(n + 1)]
for i in range(n):
    g.append([0] + list(map(int, input().split())))

def dfs(x, y, g):
    global n
    g[x][y] = cnt
    vis[x][y] = True
    dire = [(1, 0), (-1, 0), (0, -1), (0, 1)]
    for dx, dy in dire:
        nx, ny = x + dx, y + dy
        if 1 <= nx <= n and 1 <= ny <= n and g[nx][ny] != 0 and not vis[nx][ny]:
            dfs(nx, ny, g)

for i in range(1, n + 1):
    for j in range(1, n + 1):
         if g[i][j] != 0 and not vis[i][j]:
            dfs(i,  j, g)
            cnt += 1
q = deque()
for i in range(1, n + 1):
    for j in range(1, n + 1):
        if g[i][j] == 1:
            dis[i][j] = 0
            q.append((i, j))
while len(q) != 0:
    x, y = q.popleft()
    dire = [(1, 0), (-1, 0), (0, -1), (0, 1)]
    for dx, dy in dire:
        nx, ny = x + dx, y + dy
        if 1 <= nx <= n and 1 <= ny <= n and dis[nx][ny] > dis[x][y] + 1:
            dis[nx][ny] = dis[x][y] + 1
            q.append((nx, ny))

ans = int(1e9)
for i in range(1, n + 1):
    for j in range(1, n + 1):
        if g[i][j] == 2:
            ans = min(ans, dis[i][j] - 1)
print(ans)