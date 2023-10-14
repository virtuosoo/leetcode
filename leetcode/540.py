from typing import List


class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        n = len(nums)
        l, r = 0, n - 1
        while l < r:
            mid = (l + r) // 2
            if mid > 0 and nums[mid - 1] == nums[mid]:
                if (mid - 1) & 1:                       #左半段长度是奇数，说明在左边
                    r = mid - 2
                else:
                    l = mid + 1
            elif mid < n - 1 and nums[mid + 1] == nums[mid]:
                if (mid - 1) & 1:
                    r = mid - 1
                else:
                    l = mid + 2
            else:
                return mid
        return l

