import bisect

class Solution:
    def fullBloomFlowers(self, flowers: List[List[int]], persons: List[int]) -> List[int]:
        starts, ends = [], []
        for s, e in flowers:
            starts.append(s)
            ends.append(e)
        starts.sort()
        ends.sort()
        ans = []

        for t in persons:
            ns = bisect.bisect_right(starts, t)
            ne = bisect.bisect_left(ends, t)
            ans.append(ns - ne)
        return ans