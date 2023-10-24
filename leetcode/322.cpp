#include <bits/stdc++.h>
using namespace std;

//刚好装满的最小价值， 硬币价值为1
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, INT_MAX - 1);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = coins[i]; j <= amount; ++j) {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }

        if (dp[amount] == INT_MAX - 1) {
            return -1;
        } else {
            return dp[amount];
        }
    }
};