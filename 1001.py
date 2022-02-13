from collections import defaultdict
from typing import List


class Solution:
    def gridIllumination(self, n: int, lamps: List[List[int]], queries: List[List[int]]) -> List[int]:
        '''
            当row, col处有一盏灯时，cntrow[row] += 1...对角线的计数也加一
        '''
        cntrow, cntcol = defaultdict(int), defaultdict(int)
        cntduijiao1, cntduijiao2 = defaultdict(int), defaultdict(int)
        setLamps = set()
        for lamp in lamps:
            row, col = lamp[0], lamp[1]
            if (row, col) not in setLamps:
                cntrow[row] += 1
                cntcol[col] += 1
                cntduijiao1[row + col] += 1
                cntduijiao2[row - col] += 1
            setLamps.add((row, col))
        
        ans = []
        for query in queries:
            row, col = query[0], query[1]
            if cntrow[row] > 0 or cntcol[col] > 0 or cntduijiao1[row + col] > 0 or cntduijiao2[row - col] > 0:
                ans.append(1)
            else:
                ans.append(0)
            
            for i in range(-1, 2):
                for j in range(-1, 2):
                    nrow, ncol = row + i, col + j
                    if (nrow, ncol) in setLamps:
                        cntrow[nrow] -= 1
                        cntcol[ncol] -= 1
                        cntduijiao1[nrow + ncol] -= 1
                        cntduijiao2[nrow - ncol] -= 1
                        setLamps.remove((nrow, ncol))
        return ans

