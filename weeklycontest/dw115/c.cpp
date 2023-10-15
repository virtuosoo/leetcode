#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<int> dp(n);
        vector<int> pre(n, -1);
        vector<string> res;
        dp[0] = 1;
        int maxLen = 1;
        for (int i = 1; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (words[i].length() == words[j].length() && ham(words[i], words[j]) == 1 && groups[i] != groups[j]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        pre[i] = j;
                    }
                }
            }
            maxLen = max(dp[i], maxLen);
        }

        int idx = -1;
        for (int i = 0; i < n; ++i) {
            if (dp[i] == maxLen) {
                idx = i;
                break;
            }
        }
        vector<int> v;
        while (idx != -1) {
            v.push_back(idx);
            idx = pre[idx];
        }

        reverse(v.begin(), v.end());
        for (int i : v) {
            res.push_back(words[i]);
        }
        return res;

    }

    int ham(string &a, string &b) {
        int n = a.length();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                res ++;
            }
        }
        return res;
    }
};