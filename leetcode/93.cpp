#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        int n = s.length();
        function<void(int, vector<int>)> dfs = [&](int idx, vector<int> cur) {
            if (cur.size() == 4) {
                if (idx != n) {
                    return;
                }
                string a;
                for (int i = 0; i < 4; ++i) {
                    a += to_string(cur[i]);
                    if (i != 3) a += '.';
                }
                res.push_back(a);
                return;
            } 

            int left = 4 - cur.size();
            if (n - idx > 3 * left || left > n - idx) return;

            for (int len = 1; len <= 3 && idx + len - 1 < n; ++len) {
                if (s[idx] == '0' && len != 1) break;
                
                int tmp = atoi(s.substr(idx, len).c_str());
                if (tmp >= 0 && tmp <= 255) {
                    cur.push_back(tmp);
                    dfs(idx + len, cur);
                    cur.pop_back();
                }
            }
        };
        dfs(0, {});
        return res;
    }
};