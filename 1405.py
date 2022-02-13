import re


class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        q = [[a, 'a'], [b, 'b'], [c, 'c']]
        q.sort(reverse=True)

        ans = []
        while True:
            q.sort(reverse=True)
            if q[0][0] == 0:
                break
            if len(ans) >= 2 and ans[-1] == ans[-2] and ans[-1] == q[0][1]:
                if q[1][0] == 0:
                    break
                else:
                    ans.append(q[1][1])
                    q[1][0] -= 1
            else:
                ans.append(q[0][1])
                q[0][0] -= 1
        return ''.join(ans)
