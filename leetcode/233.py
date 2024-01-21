class Solution:
    def countDigitOne(self, n: int) -> int:
        res = 0
        s = str(n)
        m = len(s)
        for i in range(0, m):
            tmp = n // (10 ** i)
            res += (tmp + 8) // 10 * (10 ** i)
            if (tmp % 10 == 1):
                res += n % (10 ** i) + 1
        return res
