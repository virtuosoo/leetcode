#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int> > dp(k, vector<int>(n + 1, 0));
        int x = 1;
        for (int i = 0; i <= n; ++i) dp[0][i] = i;

        for (int i = 1; i < k; ++i) {
            x = 1;
            for (int j = 1; j <= n; ++j) {
                while (x <= j - 1 && max(dp[i - 1][x], dp[i][j - x - 1]) < 
                    max(dp[i - 1][x - 1], dp[i][j - x])) {
                        x++;
                }
                dp[i][j] = max(dp[i - 1][x - 1], dp[i][j - x]) + 1;
            }
        }
        return dp[k - 1][n];
    }
};