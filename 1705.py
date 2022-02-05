import heapq
class Solution:
    def eatenApples(self, apples, days) -> int:
        hp = []
        n = len(apples)
        ans = 0
        for i in range(n):
            if apples[i] != 0:
                heapq.heappush(hp, [i + days[i], apples[i]])
            while len(hp) != 0 and hp[0][0] <= i:
                heapq.heappop(hp)
            if len(hp) != 0 and hp[0][1] > 0:
                ans += 1
                hp[0][1] -= 1
                if hp[0][1] == 0:
                    heapq.heappop(hp)
        i = n
        print(ans)
        while len(hp) != 0:
            if hp[0][0] < i:
                heapq.heappop(hp)
            else:
                ans += min(hp[0][1], hp[0][0] - i)
                i += min(hp[0][1], hp[0][0] - i)
                heapq.heappop(hp)
        return ans

