class Solution:
    def maxValueOfCoins(self, piles: List[List[int]], k: int) -> int:
        n = len(piles)
        dp = [[0] * (k + 5) for i in range(n + 1)]
        
        prev = [[] for i in range(n + 5)]
        for i in range(n):
            for j in range(len(piles[i])):
                if j == 0:
                    prev[i].append(piles[i][j])
                else:
                    presum = prev[i][-1] + piles[i][j]
                    prev[i].append(presum)
        
        for j in range(1, min(len(piles[0]) + 1, k + 1)):
            dp[0][j] = prev[0][j - 1]

        for i in range(1, n):
            for j in range(k + 1):
                dp[i][j] = dp[i - 1][j]
                for kk in range(1, min(k + 1, len(piles[i]) + 1, j + 1)):
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - kk] + prev[i][kk - 1])
        return dp[n - 1][k]
