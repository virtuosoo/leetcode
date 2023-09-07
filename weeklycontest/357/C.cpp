#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool vis[405][405];
    int dep[405][405];

    vector<vector<int> > dire{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        memset(vis, 0, sizeof(vis));
        bfs1(grid);
        int l = 0, r = 400;

        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (bfs2(n, mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

    void bfs1(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q.push(i * n + j);
                    vis[i][j] = true;
                }
            }
        }

        while (!q.empty()) {
            int val = q.front();
            q.pop();

            int x = val / n, y = val % n;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dire[i][0], ny = y + dire[i][1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && vis[nx][ny] == false) {
                    dep[nx][ny] = dep[x][y] + 1;
                    vis[nx][ny] = true;
                    q.push(nx * n + ny);
                }
            }
        }
    }

    bool bfs2(int n, int k) {
        if (dep[0][0] < k) {
            return false;
        }
        queue<int> q;
        q.push(0);
        vis[0][0] = true;

        while (!q.empty()) {
            int val = q.front();
            q.pop();
            int x = val / n, y = val % n;
            if (x == n - 1 && y == n - 1) {
                return true;
            }
            for (int i = 0; i < 4; ++i) {
                int nx = x + dire[i][0], ny = y + dire[i][1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n 
                    && vis[nx][ny] == false && dep[nx][ny] >= k) {
                    vis[nx][ny] = true;
                    q.push(nx * n + ny);
                }
            }
        }
        return false;
    }
};