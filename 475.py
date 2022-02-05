def check(houses, heaters, x):
    n, m = len(houses), len(heaters)
    j = 0
    for i in range(n):
        while j < m and heaters[j] + x < houses[i]:
            j += 1
        if j < m and heaters[j] - x <= houses[i] <= heaters[j] + x:
            continue
        else:
            return False
    return True


class Solution:
    def findRadius(self, houses, heaters):
        l, r = 0, int(1e9)
        houses.sort()
        heaters.sort()
        while l < r:
            mid = l + r >> 1
            if check(houses, heaters, mid):
                r = mid
            else:
                l = mid + 1
        return l