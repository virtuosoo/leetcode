from typing import List

class Solution:
    def kthSmallestPrimeFraction(self, arr: List[int], k: int) -> List[int]:
        n = len(arr)
        l, r = 0.0, 1.0
        self.x, self.y = 0, 1
        arr.sort()
        def check(mid):
            cnt = 0
            i = -1
            self.x, self.y = 0, 1
            for j in range(1, n):
                while arr[i + 1] * 1.0 / arr[j] <= mid:
                    i += 1
                    if arr[i] * self.y > arr[j] * self.x:
                        self.x, self.y = arr[i], arr[j]
                cnt += i + 1
            return cnt

        eps = 1e-8
        while r - l > eps:
            mid = (l + r) / 2
            if check(mid) > k:
                r = mid
            elif check(mid) < k:
                l = mid
            else:
                return [self.x, self.y]
        
