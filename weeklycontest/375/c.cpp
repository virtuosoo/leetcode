#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), mx = 0;
        for (int a : nums) {
            mx = max(a, mx);
        }

        long long res = 0, cnt = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            if (nums[i] == mx) {
                cnt ++;
            }
            while (cnt >= k) {
                res += (n - i);
                if (nums[j] == mx) cnt--;
                j++;
            }
        }
        return res;
    }
};