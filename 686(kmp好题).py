def kmp(a, b):
    n, m = len(a), len(b)
    f = [0] * m
    for i in range(1, m):
        j = f[i - 1]
        while j and b[i] != b[j]:
            j = f[j - 1]
        if b[i] == b[j]:
            j += 1
        f[i] = j
    i, j = 0, 0
    while True:
        if i - j >= n:
            break
        print(i, j)
        while j and a[i % n] != b[j]:
            j = f[j - 1]
        if a[i % n] == b[j]:
            j += 1
        if j == m:
            return i - m + 1
        i += 1
    return -1


class Solution:
    def repeatedStringMatch(self, a: str, b: str):
        res = kmp(a, b)
        if res == -1:
            return -1
        print(res)
        if res + len(b) <= len(a):
            return 1
        else:
            return (res + len(b) + len(a) - 1) // len(a)
        

Solution().repeatedStringMatch("aaac", "aac")