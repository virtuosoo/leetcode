#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int> > directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int n = matrix.size(), m = matrix[0].size();
        int dire = 0;
        int x = 0, y = 0;
        vector<vector<bool> > vis(n, vector<bool>(m, false));

        auto valid = [&](int x, int y) -> bool {
            return x >= 0 && x < n && y >= 0 && y < m && !vis[x][y];
        };
        for (int i = 0; i < n * m; ++i) {
            vis[x][y] = true;
            res.push_back(matrix[x][y]);
            int nx = x + directions[dire][0], ny = y + directions[dire][1];
            if (!valid(nx, ny)) {
                dire = (dire + 1) % 4;
            }
            x += directions[dire][0];
            y += directions[dire][1];
        }
        return res;
    }
};