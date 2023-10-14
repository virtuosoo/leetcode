import bisect

def discretization(l: list) -> list:
    res = []
    s = sorted(l)
    for a in l:
        res.append(bisect.bisect_left(s, a) + 1)
    return res

class Solution:
    def __init__(self):
        self.n = 0
        self.f = [0] * 100005
    def lowbit(self, x):
        return x & (-x)
    def add(self, x, val):
        t = x
        while t <= self.n:
            self.f[t] += val
            t += self.lowbit(t)
    def query(self, x):
        t, res = x, 0
        while t > 0:
            res += self.f[t]
            t -= self.lowbit(t)
        return res

    def countSmaller(self, nums: List[int]) -> List[int]:
        nums = discretization(nums)
        c = []
        n = len(nums)
        self.n = n
        nums.append(0)
        nums = nums[::-1]
        for i in range(1, n + 1):
            c.append(self.query(nums[i] - 1))
            self.add(nums[i], 1)
        return c[::-1]

