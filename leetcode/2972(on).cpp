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

        long long res = n - suf + 1, tot = (1ll + n) * n / 2;
        if (pre >= suf) {
            return tot;
        }
        int i, r = suf;
        for (i = 0; i <= pre; ++i) {
            while (r < n && nums[r] <= nums[i]) {
                r++;
            }
            res += n - r + 1;
        }
        return res;
    }
};