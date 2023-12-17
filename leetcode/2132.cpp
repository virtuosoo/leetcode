#include <bits/stdc++.h>
using namespace std;

// 二维前缀和 二维差分
class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int> > sum(n + 5, vector<int>(m + 5, 0));
        vector<vector<int> > diff(n + 5, vector<int>(m + 5, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + grid[i - 1][j - 1];
            }
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (grid[i][j] == 0) {
                    int x = i + stampHeight - 1, y = j + stampWidth - 1;
                    if (x <= n && y <= m &&
                        sum[x][y] - sum[i - 1][y] - sum[x][j - 1] + sum[i - 1][j - 1] == 0) { //可以放
                        diff[i][j]++;
                        diff[i][y + 1]--;
                        diff[x + 1][j]--;
                        diff[x + 1][y + 1]++;
                    }
                }
            }
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                diff[i][j] = diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1] + diff[i][j];
                if (diff[i][j] == 0 && grid[i - 1][j - 1] == 0) {
                    return false;
                }
            }
        }
        return true;
    }
};