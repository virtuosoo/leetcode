import bisect

class Solution:
    def numFriendRequests(self, ages: List[int]) -> int:
        n = len(ages)
        num = [0] * 130
        ans = 0
        for age in ages:
            num[age] += 1
        for i in range(1, 121):
            if num[i] == 0:
                continue
            for j in range(1, i):
                if (j - 7) * 2 > i:
                    ans += num[j] * num[i]
            #print(i, ans)
            ans += (num[i] - 1) * num[i]
        return ans

        