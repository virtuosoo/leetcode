#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        vector<int> mp(n);
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                stk.push(i);
            }

            if (s[i] == ')') {
                mp[i] = stk.top();
                mp[stk.top()] = i;
                stk.pop();
            }
        }

        string res;
        int dire = 1, idx = 0;
        while (idx != n) {
            if (s[idx] == '(' || s[idx] == ')') {
                dire *= -1;
                idx = mp[idx] + dire;
            } else {
                res += s[idx];
                idx += dire;
            }
        }
        return res;
    }
};