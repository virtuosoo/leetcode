#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length(), m = p.length();
        if (n < m) {
            return {};
        }
        vector<int> res, cnts(26, 0), cntp(26, 0);
        auto check = [&]() -> bool {
            for (int i = 0; i < 26; ++i) {
                if (cnts[i] != cntp[i]) {
                    return false;
                }
            }
            return true;
        };
        for (int i = 0; i < m; ++i) {
            cntp[p[i] - 'a']++;
        }

        for (int i = 0; i < n; ++i) {
            cnts[s[i] - 'a']++;
            if (i >= m - 1) {
                if (check()) {
                    res.push_back(i - m + 1);
                }
                cnts[s[i - m + 1] - 'a']--;
            }
        }
        return res;
    }
};