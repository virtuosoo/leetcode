#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(), res = 0, sum = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) sum--;
            else sum++;
            if (mp.find(sum) == mp.end()) {
                mp[sum] = i;
            } else {
                res = max(res, i - mp[sum]);
            }
        }
        return res;
    }
};