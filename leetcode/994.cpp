#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int> > directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int freshCnt = 0;
        auto validPos = [&](int x, int y) {
            return x < n && x >= 0 && y < m && y >= 0;
        };

        vector<vector<bool> > vis(n, vector<bool>(m, false));
        vector<vector<int> > dis(n, vector<int>(m, 0));
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    q.push(i * m + j);
                }
                if (grid[i][j] == 1) {
                    freshCnt++;
                }
            }
        }

        while (!q.empty()) {
            int t = q.front();
            q.pop();
            int x = t / m, y = t % m;
            for (int i = 0; i < 4; ++i) {
                int nx = x + directions[i][0], ny = y + directions[i][1];
                if (validPos(nx, ny) && !vis[nx][ny] && grid[nx][ny] == 1) {
                    vis[nx][ny] = true;
                    dis[nx][ny] = dis[x][y] + 1;
                    q.push(nx * m + ny);
                    freshCnt--;
                }
            }
        }

        if (freshCnt > 0) {
            return -1;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    ans = max(ans, dis[i][j]);
                }
            }
        }
        return ans;
    }
};