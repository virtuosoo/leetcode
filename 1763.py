class Solution:
    def longestNiceSubstring(self, s: str) -> str:
        n = len(s)
        idx, ans = -1, 0
        for i in range(n):
            stateLower, stateUpper = 0, 0
            for j in range(i, n):
                if 'a' <= s[j] <= 'z':
                    stateLower |= 1 << (ord(s[j]) - ord('a'))
                else:
                    stateUpper |= 1 << (ord(s[j]) - ord('A'))
                
                if stateLower == stateUpper and j - i + 1 > ans:
                    print(i, j, ans)
                    ans = j - i + 1
                    idx = i
        return "" if idx == -1 else s[idx:idx + ans]
