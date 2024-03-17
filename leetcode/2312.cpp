#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        long long res = 0;
        vector<vector<long long> > dp(m + 1, vector<long long>(n + 1, 0));

        for (auto &p : prices) {
            int h = p[0], w = p[1], v = p[2];
            dp[h][w] = max(dp[h][w], 1ll * v);
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i > 1) {
                    for (int k = 1; k < i / 2 + 1; ++k) {
                        dp[i][j] = max(dp[i][j], dp[k][j] + dp[i - k][j]);
                    }
                }

                if (j > 1) {
                    for (int k = 1; k < j / 2 + 1; ++k) {
                        dp[i][j] = max(dp[i][j], dp[i][k] + dp[i][j - k]);
                    }
                }
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};