#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res, diff = 1e9;

        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1, k = n - 1;
            while (j < k) {
                if (abs(nums[j] + nums[k] - (target - nums[i])) < diff) {
                    diff = abs(nums[j] + nums[k] - (target - nums[i]));
                    res = nums[j] + nums[k] + nums[i];
                } else if (nums[j] + nums[k] <= target - nums[i]) {
                    ++j;
                } else {
                    --k;
                }
            }  
        }
        return res;
    }
};