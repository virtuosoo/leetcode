#include <bits/stdc++.h>
using namespace std;

//01背包, 重量为nums[i]， 价值为1
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(20005, INT_MIN);
        dp[0] = 0;
        int sum = 0;
        for (int &a : nums) {
            sum += a;
        }
        if (sum % 2 != 0) {
            return false;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = sum; j >= nums[i]; --j) {
                dp[j] = max(dp[j], dp[j - nums[i]] + 1);
            }
        }
        return dp[sum / 2] > 0;
    }
};