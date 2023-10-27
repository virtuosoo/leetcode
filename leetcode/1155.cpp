#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MOD = 1e9 + 7;
        auto dp = vector<vector<int> > (n + 1, vector<int> (target + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                for (int x = j; x <= target; ++x) {
                    dp[i][x] = (dp[i][x] + dp[i - 1][x - j]) % MOD;
                }
            }
        }
        return dp[n][target];
    }
};