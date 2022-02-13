import queue
from typing import List
from collections import deque

class Solution:
    def dfs(self, x, y, grid):
        grid[x][y] = 0
        self.val += 1

        for nx, ny in ((x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)):
            if 0 <= nx < len(grid) and 0 <= ny < len(grid[0]) and grid[nx][ny] == 1:
                self.dfs(nx, ny, grid)

    def numEnclaves(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        total = sum([sum(a) for a in grid])

        self.val = 0
        for i in range(n):
            for j in range(m):
                if (i == 0 or j == 0 or i == n - 1 or j == m - 1) and grid[i][j] == 1:
                    self.dfs(i, j, grid)
        return total - self.val




