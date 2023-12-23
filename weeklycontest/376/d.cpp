#include <bits/stdc++.h>
using namespace std;

//中位数贪心，双指针滑动窗口
class Solution {
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> sum(n + 1);
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        auto calc = [&](int l, int mid, int r) {
            long long res = 0;
            res += (long long) (mid - l + 1) * nums[mid] - (sum[mid + 1] - sum[l]); //[l, mid]
            res += sum[r + 1] - sum[mid + 1] - (long long) (r - mid) * nums[mid];  //[mid + 1, r]
            return res;
        };

        int ans = 0;
        int l = 0, r = 0;
        for (; r < n; ++r) {
            while (calc(l, (l + r) / 2, r) > k) {
                ++l;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};