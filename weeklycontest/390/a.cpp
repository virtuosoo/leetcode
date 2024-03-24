#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        vector<int> cnt(26, 0);
        int r = 0, ans = 0;
        for (int i  = 0; i < n; ++i) {
            while (r < n && cnt[s[r] - 'a'] < 2) {
                cnt[s[r] - 'a']++;
                r++;
            }
            ans = max(r - i, ans);
            cnt[s[i] - 'a']--;
        }
        return ans;
    }
};