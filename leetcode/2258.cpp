#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int> > dire = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int> > reach(m, vector<int>(n ,0));
        vector<vector<int> > vis(m, vector<int>(n ,0))
        queue<tuple<int, int, int> > q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q.push(make_tuple(i, j, 0));
                    vis[i][j] = 1;
                }
            }
        }

        while (!q.empty()) {
            auto tp = q.front();
            int x = tp[0], y = tp[1], t = tp[2];
            reach[x][y] = t;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dire[i][0], ny = y + dire[i][1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny] && grid[nx][ny] == 0) {
                    vis[nx][ny] = 1;
                    q.push(make_tuple(nx, ny, t + 1));
                }
            }
        }
    }
};