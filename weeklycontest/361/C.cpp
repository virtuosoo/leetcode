#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        vector<int> pre(n + 1);
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + (nums[i] % modulo == k);
        }
        long long res = 0;
        map<int, int> cnt;
        cnt[0] = 1;
        for (int i = 1; i <= n; ++i) {
            res += cnt[(pre[i] - k + modulo) % modulo];
            cnt[pre[i] % modulo]++;
        }
        return res;
    }
};