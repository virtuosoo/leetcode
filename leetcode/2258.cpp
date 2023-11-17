#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int> > dire = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int> > reach(m, vector<int>(n ,-1)); //-1表示火不可达
        vector<vector<int> > vis(m, vector<int>(n ,0));
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
            q.pop();
            auto [x, y, t] = tp;
            reach[x][y] = t;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dire[i][0], ny = y + dire[i][1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny] && grid[nx][ny] == 0) {
                    vis[nx][ny] = 1;
                    q.push(make_tuple(nx, ny, t + 1));
                }
            }
        }

        auto check = [&](int x) -> bool {
            queue<tuple<int, int, int> > q;
            q.push(make_tuple(0, 0, x));
            vector<vector<int> > vis(m, vector<int>(n ,0));
            vis[0][0] = 1;
            while (!q.empty()) {
                auto tp = q.front();
                q.pop();
                auto [x, y, t] = tp;
                for (int i = 0; i < 4; ++i) {
                    int nx = x + dire[i][0], ny = y + dire[i][1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && 
                        !vis[nx][ny] && grid[nx][ny] == 0) {
                        if (nx == m - 1 && ny == n - 1 && (reach[nx][ny] >= t + 1 || reach[nx][ny] == -1)) {
                            return true;
                        }
                        if (reach[nx][ny] > t + 1 || reach[nx][ny] == -1) {
                            vis[nx][ny] = 1;
                            q.push(make_tuple(nx, ny, t + 1));
                        }
                    }
                }
            }
            return false;
        };

        if (!check(0)) {
            return -1;
        }
        int l = 0, r = 1e9;
        while (l < r) {
            int x = (l + r + 1) / 2;
            //printf("%d %d\n", l, r);
            if (check(x)) {
                l = x;
            } else {
                r = x - 1;
            }
        }
        return l;
    }
};