#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int twoEggDrop(int n) {
        vector<int> dp(n + 1, 100005);
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i - 1; ++j) {
                dp[i] = min(dp[i], max(j, dp[i - j] + 1));
            }
        }
        return dp[n];
    }
};