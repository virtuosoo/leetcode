#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> fa(n * m);
        for (int i = 0; i < n * m; ++i) {
            fa[i] = i;
        }
        function<int(int)> find = [&](int x) {
            if (x == fa[x]) {
                return x;
            }
            return fa[x] = find(fa[x]);
        };

        function<void(int, int)> merge = [&](int x, int y) {
            int fx = find(x), fy = find(y);
            if (fx != fy) {
                fa[fx] = fy;
            }
        };
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    int x = i * m + j, y;
                    if (i > 0 && grid[i - 1][j] == '1') {
                        y = (i - 1) * m + j;
                        merge(x, y);
                    }

                    if (j > 0 && grid[i][j - 1] == '1') {
                        y = i * m + j - 1;
                        merge(x, y);
                    }
                }

            }
        }
        int ans = 0;
        for (int i = 0; i < n * m; ++i) {
            if (grid[i / m][i % m] == '1' && i == find(i)) {
                ans++;
            }
        }
        return ans;
    }
};