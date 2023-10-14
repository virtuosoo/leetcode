class Solution:
    def trap(self, h: List[int]) -> int:
        n = len(h)
        lmax, rmax = [0] * (n + 5), [0] * (n + 5)
        lmax[0], rmax[n -1] = h[0], h[n - 1]
        for i in range(1, n):
            lmax[i] = max(h[i], lmax[i - 1])
        for i in range(n - 2, -1, -1):
            rmax[i] = max(rmax[i + 1], h[i])
        ans = 0
        for i in range(1, n - 1):
            ans += min(lmax[i], rmax[i]) - h[i]
        return ans