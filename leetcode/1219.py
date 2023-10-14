from typing import List


class Solution:
    def dfs(self, x, y, sum, grid):
        self.vis[x][y] = True
        self.ans = max(self.ans, sum)
        for i in range(4):
            nx, ny = x + self.dx[i], y + self.dy[i]
            if 0 <= nx < self.n and 0 <= ny < self.m and grid[nx][ny] != 0 and not self.vis[nx][ny]:
                self.dfs(nx, ny, sum + grid[nx][ny], grid)
        self.vis[x][y] = False

    def getMaximumGold(self, grid: List[List[int]]) -> int:
        self.n, self.m = len(grid), len(grid[0]
        )
        self.vis = [[False] * self.m for i in range(self.n)]

        self.dx = [0, 0, -1, 1]
        self.dy = [-1, 1, 0, 0]

        self.ans = 0

        for i in range(self.n):
            for j in range(self.m):
                if grid[i][j] != 0:
                    self.dfs(i, j, grid[i][j], grid)
        return self.ans

        