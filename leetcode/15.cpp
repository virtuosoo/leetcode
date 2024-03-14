#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        map<vector<int>, int> mp;
        vector<vector<int>> res;
        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1, k = n - 1;
            while (j < k) {
                if (nums[j] + nums[k] == -nums[i]) {
                    vector<int> t{nums[i], nums[j], nums[k]};
                    res.push_back(t);
                    for (++j; j < k && nums[j] == nums[j - 1]; ++j);
                    for (--k; j < k && nums[k] == nums[k + 1]; --k);
                } else if (nums[j] + nums[k] < -nums[i]) {
                    ++j;
                } else {
                    --k;
                }
            }  
        }
        return res;
    }
};