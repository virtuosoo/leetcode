from collections import deque

class Solution:
    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
        dp = [[[0] * (k + 5) for i in range(n)] for j in range(n)]
        inque = [[[False] * (k + 5) for i in range(n)] for j in range(n)]
        q = deque()
        dp[row][column][0] = 1.0

        q.append((row, column, 0))
        inque[row][column][0] = True

        ans = 0.0
        while q:
            x, y, step = q[0]
            if step == k:
                ans += dp[x][y][step]
            q.popleft()
            inque[x][y][step] = False
            for nx, ny in ((x - 2, y - 1), (x - 1, y - 2), (x + 1, y - 2), (x + 2, y - 1), (x + 2, y + 1), (x + 1, y + 2), (x - 1, y + 2), (x - 2, y + 1)):
                if 0 <= nx < n and 0 <= ny < n and step + 1 <= k:
                    dp[nx][ny][step + 1] += dp[x][y][step] * (1 / 8)
                    if not inque[nx][ny][step + 1]:
                        q.append((nx, ny, step + 1))
                        inque[nx][ny][step + 1] = True
        return ans
        
       
