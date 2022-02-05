class Solution:
    def longestValidParentheses(self, s: str) -> int:
        n = len(s)
        dp = [0] * (n + 5)
        ans  = 0
        for i in range(1, n):
            if s[i] == ")":
                if s[i - 1] == "(":
                    dp[i] = max(dp[i], dp[i - 2] + 2)
                elif i - dp[i - 1] - 1 >= 0:
                    pre = i - dp[i - 1] - 1
                    if s[pre] == "(":
                        dp[i] = max(dp[i], dp[i - 1] + 2 + dp[pre - 1])
            ans = max(ans, dp[i])
        print(dp)
        return ans