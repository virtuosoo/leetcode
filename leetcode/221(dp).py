from typing import List


class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        n, m = len(matrix), len(matrix[0])
        dp = [[0] * (m + 1) for i in range(n + 1)]
        ans = 0
        for i in range(n):
            for j in range(m):
                if int(matrix[i][j]) == 0:
                    dp[i][j] = 0
                else:
                    if i == 0 or j == 0:
                        dp[i][j] = int(matrix[i][j])
                    else:
                        dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1
                    ans = max(ans, dp[i][j] * dp[i][j])
        return ans