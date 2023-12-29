#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> sum(n + 1);
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i  - 1] + nums[i - 1];
        }

        for (int i = n; i >= 3; --i) {
            if (sum[i - 1] > nums[i - 1]) {
                return sum[i];
            }
        }
        return -1;
    }
};