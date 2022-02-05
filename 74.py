from typing import List

def bise(l, r, check):
    while l < r:
        mid = l + r + 1 >> 1
        if check(mid):
            r = mid - 1
        else:
            l = mid
    return l

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        n, m = len(matrix), len(matrix[0])
        col = bise(0, n - 1, lambda x : matrix[x][0] > target)
        if matrix[col][0] > target:
            return False
        row = bise(0, m - 1, lambda x : matrix[col][x] > target)
        return matrix[col][row] == target