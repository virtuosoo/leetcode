#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int sum = 0, ans = 0;
        cnt[0] = 1;
        for (int a : nums) {
            sum += a;
            ans += cnt[sum - k];
            cnt[sum]++;
        }
        return ans;
    }
};