from typing import List


class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        ans = []
        n, m = len(grid), len(grid[0])
        for i in range(m):
            ret = -1
            x, y = 0, i
            while True:
                if grid[x][y] == 1:
                    if y + 1 == m or grid[x][y] != grid[x][y + 1]:
                        ret = -1
                        break
                    x, y = x + 1, y + 1
                else:
                    if y - 1 < 0 or grid[x][y] != grid[x][y - 1]:
                        ret = -1
                        break
                    x, y = x + 1, y - 1
                if x == n:
                    ret = y
                    break
            ans.append(ret)
        return ans



