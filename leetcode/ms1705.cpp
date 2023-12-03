#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        int n = array.size();
        int maxLen = 0, idx = -1, sum = 0;
        map<int, int> mp;
        mp[0] = -1;
        for (int i = 0; i < n; ++i) {
            string &s = array[i];
            if (s[0] >= '0' && s[0] <= '9') {
                sum += 1;
            } else {
                sum -= 1;
            }
            if (mp.find(sum) != mp.end()) {
                if (i - mp[sum] > maxLen) {
                    maxLen = i - mp[sum];
                    idx = mp[sum] + 1;
                }
            } else {
                mp[sum] = i;
            }
        }
        if (idx == -1) {
            return {};
        } else {
            return {array.begin() + idx, array.begin() + idx + maxLen};
        }
    }
};