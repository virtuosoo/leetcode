#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();

        vector<int> dis(n * m, INT_MAX);
        vector<bool> vis(n * m, false);

        dis[0] = 0;

        priority_queue<pair<int, int> > q;
        q.emplace(make_pair(0, 0));
        printf("%d %d\n", n, m);
        while (!q.empty()) {
            int u = q.top().second;
            int x = u / n, y = u % n;
            q.pop();

            if (vis[u]) {
                continue;
            }
            vis[u] = true;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dirs[i][0], ny = y + dirs[i][1];
                int v = nx * n + ny, d = dis[u];
                printf("%d %d %d %d\n", nx, ny, x, y);
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && max(d, abs(heights[x][y] - heights[nx][ny])) < dis[v]) {
                    dis[v] = max(d, abs(heights[x][y] - heights[nx][ny]));
                    q.push(make_pair(-dis[v], v));
                }
            }
        }
        return dis[n * m - 1];
    }
};