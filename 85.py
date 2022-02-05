from typing import List

class Solution:
    def maximalRectangle(self, mat: List[List[str]]) -> int:
        n, m = len(mat), len(mat[0])
        up = [[0] * m for i in range(n)]
        l = [[0] * m for i in range(n)]
        r = [[0] * m for i in range(n)]
        for i in range(n):
            for j in range(m):
                if mat[i][j] == '1':
                    up[i][j] = 1
                    l[i][j] = r[i][j] = j
        for i in range(n):
            for j in range(1, m):
                if mat[i][j] == mat[i][j - 1] and  mat[i][j - 1] == '1':
                    l[i][j] = l[i][j - 1]
            for j in range(m - 2, -1, -1):
                if mat[i][j] == mat[i][j + 1] and  mat[i][j + 1] == '1':
                    r[i][j] = r[i][j + 1]
        
        res = 0
        for i in range(n):
            for j in range(m):
                if i > 0 and mat[i][j] == mat[i - 1][j] == '1':
                    up[i][j] = up[i - 1][j] + 1
                    r[i][j] = min(r[i][j], r[i - 1][j])
                    l[i][j] = max(l[i][j], l[i - 1][j])
                res = max(res, up[i][j] * (r[i][j] - l[i][j] + 1))
        return res
