#include <bits/stdc++.h>
using namespace std;

//01背包, 重量为nums[i]， 价值为1
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(20005, false);
        dp[0] = true;
        int sum = 0;
        for (int &a : nums) {
            sum += a;
        }
        if (sum % 2 != 0) {
            return false;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = sum; j >= nums[i]; --j) {
                dp[j] = dp[j] | dp[j - nums[i]];
            }
        }
        return dp[sum / 2];
    }
};