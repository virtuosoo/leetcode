#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int n = s.length();
        vector<int> pre(n + 1);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int c = 0;
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
                s[i] == 'o' || s[i] == 'u') {
                    c = 1;
                }
            pre[i + 1] = pre[i] + c;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                int len = i - j + 1, p = pre[i] - pre[j - 1];
                if (len == 2 * p && p * p % k == 0) {
                    res ++;
                } 
            }
        }
        return res;
    }
};