#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
        }
        
        if ((sum + target) % 2 == 1 || -target > sum) {
            return 0;
        }

        int d = (sum + target) / 2;
        
        vector<int> dp(d + 1);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = d; j >= nums[i]; --j) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[d];
    }
};