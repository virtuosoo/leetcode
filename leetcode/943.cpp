#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
        int n = words.size(), mask = (1 << n);
        vector<vector<int> > overlap(n, vector<int>(n, 0));

        vector<vector<int> > parent(mask, vector<int>(n, -1));
        vector<vector<int> > dp(mask, vector<int>(n, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int l1 = words[i].length(), l2 = words[j].length(), lmin = min(l1, l2);
                for (int k = lmin; k >= 0; --k) {
                    if (words[i].substr(l1 - k, k) == words[j].substr(0, k)) {
                        overlap[i][j] = k;
                        break;
                    }
                }
            }
        }
        
        for (int s = 0; s < mask; ++s) {
            for (int i = 0; i < n; ++i) { //枚举状态s中最后一个加入的字符串
                if (((s >> i) & 1) == 0) continue;
                for (int j = 0; j < n; ++j) {
                    if (((s >> j) & 1) != 0) continue;
                    int val = dp[s][i] + overlap[i][j];
                    if (dp[s | (1 << j)][j] <= val) {
                        dp[s | (1 << j)][j] = val;
                        parent[s | (1 << j)][j] = i;
                    }
                }
            }
        }

        int idx = -1, mx = 0;
        for (int i = 0; i < n; ++i) {
            if (mx <= dp[mask - 1][i]) {
                idx = i;
                mx = dp[mask - 1][i];
            }
        }

        int state = mask - 1, p;
        string ans = words[idx];
        while (true) {
            p = parent[state][idx];
            if (p == -1) {
                break;
            }
            int left = words[p].length() - overlap[p][idx];
            ans = words[p].substr(0, left) + ans;
            state ^= (1 << idx);
            idx = p;
        }
        return ans;
    }
};

int main()
{
    vector<string> words{"alex","loves","leetcode"};
    Solution().shortestSuperstring(words);
}