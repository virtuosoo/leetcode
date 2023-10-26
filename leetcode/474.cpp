#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int siz = strs.size();
        vector<int> w0(siz), w1(siz);
        for (int i = 0; i < siz; ++i) {
            for (char c : strs[i]) {
                if (c == '0') {
                    w0[i]++;
                } else {
                    w1[i]++;
                }
            }
        }
        auto dp = vector<vector<int> > (m + 1, vector<int> (n + 1, 0));
        for (int i = 0; i < siz; ++i) {
            for (int j = m; j >= w0[i]; --j) {
                for (int k = n; k >= w1[i]; --k) {
                    dp[j][k] = max(dp[j][k], dp[j - w0[i]][k - w1[i]] + 1);
                }
            }
        }
        return dp[m][n];
    }
};