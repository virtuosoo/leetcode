class Solution:
    def maxCoins(self, nums):
        n = len(nums)
        nums = [1] + nums + [1]
        dp = [[0] * (n + 5) for i in range(n + 5)]

        for l in range(2, n + 2):
            for i in range(0, n + 1):
                if i + l - 1 > n + 1:
                    break
                j = i + l - 1
                if i == 0 and j == n + 1:
                    print("?")
                for mid in range(i + 1, j):
                    coins = nums[i] * nums[mid] * nums[j]
                    dp[i][j] = max(dp[i][j], coins + dp[i][mid] + dp[mid][j])
        return dp[0][n + 1]