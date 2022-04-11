import heapq

class Solution:
    def minimumWeight(self, n: int, edges: List[List[int]], src1: int, src2: int, dest: int) -> int:
        g = [[] for i in range(n)]
        grev = [[] for i in range(n)]

        for edge in edges:
            g[edge[0]].append((edge[1], edge[2]))
            grev[edge[1]].append((edge[0], edge[2]))

        def dijk(g, start, n):
            vis = [False] * n
            dis = [int(1e18)] * n
            dis[start] = 0

            q =[]
            heapq.heappush(q, (0, start))
            while len(q) != 0:
                u = heapq.heappop(q)[1]
                if vis[u]:
                    continue
                vis[u] = True
                for v, val in g[u]:
                    if dis[u] + val < dis[v]:
                        dis[v] = dis[u] + val
                        heapq.heappush(q, (dis[v], v))
            return dis

        dis1 = dijk(g, src1, n)
        dis2 = dijk(g, src2, n)
        dis3 = dijk(grev, dest, n)

        ans = int(1e18)
        
        for c in range(n):
            ans = min(ans, dis1[c] + dis2[c] + dis3[c])

        return ans if ans != int(1e18) else -1
