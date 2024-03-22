#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n = word.length();
        vector<int> cnt(26, 0);
        for (char c : word) {
            cnt[c - 'a']++;
        }

        int ans = 1e9;
        sort(cnt.begin(), cnt.end());
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] == 0) continue;

            int t = 0;
            for (int j = 0; j < i; ++j) {
                t += cnt[j];
            }

            for (int j = i; j < 26; ++j) {
                t += max(0, cnt[j] - (cnt[i] + k));
            }
            ans = min(ans, t);
        }
        return ans;
    }
};