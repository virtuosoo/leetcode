from typing import List

import math

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

class Solution:
    def simplifiedFractions(self, n: int) -> List[str]:
        ans = []
        for i in range(1, n + 1):
            for j in range(1, i):
                if gcd(j, i) == 1:
                    ans.append(str(j) + '/' + str(i))
        return ans

        