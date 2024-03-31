#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> cntt, cnts;
        for (char c : t) {
            cntt[c]++;
        }
        int nt = cntt.size(), ns = 0, len = s.length();
        int start = -1, minn = 1e9;
        int r = 0;
        for (int i = 0; i < len; ++i) {
            while (r < len && ns < nt) {
                cnts[s[r]]++;
                if (cntt.find(s[r]) != cntt.end() 
                    && cnts[s[r]] == cntt[s[r]]) {
                    ns++;
                }
                r++;
            }
            if (ns == nt && r - i < minn) {
                minn = r - i;
                start = i;
            }
            cnts[s[i]]--;
            if (cntt.find(s[i]) != cntt.end()
                && cnts[s[i]] == cntt[s[i]] - 1) {
                ns--;
            }
        }
        if (start == -1) return "";
        else return s.substr(start, minn);
    }
};