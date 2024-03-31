#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long res = 0, cur = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i == 0 || nums[i] == nums[i - 1]) {
                res += (cur + 1) * cur / 2;
                cur = 1;
            } else {
                cur++;
            }
        }
        res += (cur + 1) * cur / 2;
        return res;
    }
};