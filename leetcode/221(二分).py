from typing import List


class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        n, m  = len(matrix), len(matrix[0])
        pre = [[0] * (m + 1) for i in range(n + 1)]
        dp = [[0] * (m + 1) for i in range(n + 1)]
        for i in range(n):
            for j in range(m):
                pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + int(matrix[i][j])

        ans = 0
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == '0':
                    continue
                l, r = 1, min(i + 1, j + 1)
                while l < r:
                    mid = (l + r + 1) >> 1
                    i1, j1 = i - mid + 1, j - mid + 1
                    if pre[i][j] - pre[i1 - 1][j] - pre[i][j1 - 1] + pre[i1 - 1][j1 - 1] == mid * mid: # 可以形成正方形
                        l = mid
                    else:
                        r = mid - 1
                ans = max(l * l, ans)
        return ans

