'''
    leetcode 600
    给定一个正整数 n，找出小于或等于 n 的非负整数中，其二进制表示不包含 “连续的1” 的个数。
    很典型的数位dp，dp[pos][pre]表示枚举到pos位置，前一位为pre时的方案数。

'''

class Solution:
    def findIntegers(self, n: int) -> int:
        a = []
        dp = [[-1] * 2 for i in range(40)]
        tmp = n
        while tmp:
            a.append(tmp & 1)
            tmp >>= 1
        siz = len(a)
        ans = self.dfs(siz - 1, 0, True, dp, a)
        return ans

    def dfs(self, pos, pre, limit, dp, a):
        if pos == -1:
            return 1
        if not limit and dp[pos][pre] != -1:
            return dp[pos][pre]
        up = a[pos] if limit else 1
        ans = 0
        for i in range(up + 1):
            if i == 1 and pre == 1: #约束条件，前一位为1时，这一位就不能为1了
                continue
            ans += self.dfs(pos - 1, i, (limit and i == up), dp, a)
        dp[pos][pre] = ans
        return ans