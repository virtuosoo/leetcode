#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int mask1 = 0, mask2 = 0;
        vector<int> cnt1(26), cnt2(26);
        for (char c : word1) {
            mask1 |= (1 << (c - 'a'));
            cnt1[c - 'a']++;
        }
        for (char c : word2) {
            mask2 |= (1 << (c - 'a'));
            cnt2[c - 'a']++;
        }

        if (mask1 != mask2) return false;
        sort(cnt1.begin(), cnt1.end());
        sort(cnt2.begin(), cnt2.end());
        for (int i = 0; i < 26; ++i) {
            if (cnt1[i] != cnt2[i]) {
                return false;
            }
        }
        return true;
    }
};