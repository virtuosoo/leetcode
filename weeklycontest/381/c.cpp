#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> cnt(26);
        for (char c : word) {
            cnt[c - 'a']++;
        }
        sort(cnt.begin(), cnt.end(), greater<int>());
        int ans = 0;
        for (int i = 0; i <= 3; ++i) {
            for (int j = i * 8; j < min((i + 1) * 8, 26); ++j) {
                ans += (i + 1) * cnt[j];
            }
        }
        return ans;
    }
};