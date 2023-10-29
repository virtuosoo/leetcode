#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        int n = nums.size();
        auto dp = vector<vector<long long> > (n, vector<long long> (3, 0));

        for (int j = 0; j < 3; ++j) {
            dp[2][2 - j] = nums[j] >= k ? 0 : (k - nums[j]);
        }

        for (int i = 3; i < n; ++i) {
            dp[i][1] = dp[i - 1][0];
            dp[i][2] = dp[i - 1][1];
            dp[i][0] = (nums[i] >= k ? 0 : (k - nums[i])) + min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2]));

            printf("i(%d), %d %d %d\n", i, dp[i][0], dp[i][1], dp[i][2]);
        }
        return min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
    }
};