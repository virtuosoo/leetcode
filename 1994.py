from typing import List


class Solution:
    def numberOfGoodSubsets(self, nums: List[int]) -> int:
        MOD = int(1e9 + 7)
        n = len(nums)
        prime = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
        canAdd = prime + [6, 10, 14, 15, 21, 22, 26, 30]
        cnt = [0] * 31

        mask = 1 << 10 #30以内只有10个质数
        f = [[0] * mask for i in range(31)]
        for i in range(1, 31):
            f[i][0] = 1
        
        for a in nums:
            cnt[a] += 1

        for i in range(2, 31):
            for state in range(0, mask):
                f[i][state] = f[i - 1][state]
            if i not in canAdd or cnt[i] == 0:
                continue

            cur = 0
            for j in range(10):
                if i % prime[j] == 0:
                    cur |= (1 << j)
            
            for state in range(0, mask):
                if state & cur == cur:
                    f[i][state] = (f[i][state] + f[i - 1][state - cur] * cnt[i]) % MOD
            
        ans = 0
        for i in range(1, mask):
            ans = (ans + f[30][i]) % MOD
            
        for i in range(cnt[1]):
            ans = (ans * 2) % MOD
        return ans
            