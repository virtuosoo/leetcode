from decimal import InvalidContext
from typing import List

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        n, m = len(nums1), len(nums2)

        def getKthElement(k):
            index1, index2 = 0, 0
            while True:
                if index1 == n:
                    return nums2[index2 + k - 1]
                if index2 == m:
                    return nums1[index1 + k - 1]
                if k == 1:
                    return min(nums1[index1], nums2[index2])

                offset = k // 2 - 1
                newindex1 = min(index1 + offset, n - 1)
                newindex2 = min(index2 + offset, m - 1)
                if nums1[newindex1] <= nums2[newindex2]:
                    k -= newindex1 - index1 + 1
                    index1 = newindex1 + 1
                else:
                    k -= newindex2 - index2 + 1
                    index2 = newindex2 + 1
            
        if (m + n) & 1:
            return getKthElement((m + n) // 2 + 1)
        else:
            return (getKthElement((m + n) // 2) + getKthElement((m + n) // 2 + 1)) / 2