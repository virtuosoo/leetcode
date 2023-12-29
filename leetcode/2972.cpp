#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 1;
        }
        int suf = 0;    //从suf开始，[i ~ n - 1]是严格递增序列， suf <= i < n;
        int pre = n - 1;   // [0 ~ i] 是严格递增序列，  0 <= i <= pre;
        for (int i = n - 1; i >= 1; --i) {
            if (nums[i - 1] >= nums[i]) {
                suf = i;
                break;
            }
        }

        for (int i = 0; i <= n - 2; ++i) {
            if (nums[i] >= nums[i + 1]) {
                pre = i;
                break;
            }
        }

        long long res = 1, tot = (1ll + n) * n / 2;
        if (pre >= suf) {
            return tot;
        }

        for (int i = 0; i < n; ++i) {
            if (i <= pre) {
                int r = upper_bound(nums.begin() + suf, nums.end(), nums[i]) - nums.begin();
                res += (n - r + 1);
            }
            if (i >= suf) {
                res++;
            }
        }
        return res;
    }
};