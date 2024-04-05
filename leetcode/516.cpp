#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int> > dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) dp[i][i] = 1;

        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i < n; ++i) {
                int j = i + len - 1;
                if (j >= n) break;

                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                int tmp = s[i] == s[j] ? 2 : 0;
                dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + tmp);
            }
        }
        return dp[0][n - 1];
    }
};