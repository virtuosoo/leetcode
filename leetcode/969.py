
'''
    给你一个整数数组 arr ，请使用 煎饼翻转 完成对数组的排序。

    一次煎饼翻转的执行过程如下：

    选择一个整数 k ，1 <= k <= arr.length
    反转子数组 arr[0...k-1]（下标从 0 开始）
    例如，arr = [3,2,1,4] ，选择 k = 3 进行一次煎饼翻转，反转子数组 [3,2,1] ，得到 arr = [1,2,3,4] 。

    以数组形式返回能使 arr 有序的煎饼翻转操作所对应的 k 值序列。任何将数组排序且翻转次数在 10 * arr.length 范围内的有效答案都将被判断为正确。

    考虑如何实现翻转任意区间[l, r]，发现反转长度为r + 1的前缀后，再反转长度为目的区间长度r - l + 1的前缀，
    最后再反转长度为r + 1的前缀，这样三次翻转实现了翻转任意区间，操作数量不超过3 * arrlength次，符合题意。

'''
from typing import List

def rev(arr, l, r):
    length = r - l + 1
    for i in range(length // 2):
        arr[l + i], arr[r - i] = arr[r - i], arr[l + i]


class Solution:
    def pancakeSort(self, arr: List[int]) -> List[int]:
        n = len(arr)
        ans = []
        for i in range(1, n + 1):
            l, r = i - 1, n - 1
            for j in range(i - 1, n):
                if arr[j] == i:
                    r = j
                    break
            #print(l, r, arr)
            if l == r:
                continue
            ans.append(r + 1)
            length = r - l + 1
            if length != 0:
                ans.append(length)
                ans.append(r + 1)
            rev(arr, l, r)
        return ans