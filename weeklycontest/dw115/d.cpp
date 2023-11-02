#include <bits/stdc++.h>
using namespace std;

/*
    推导公式
    哈希表cnt计数nums出现的个数
    f[i][j]表示用前i种数，得到和为j的方案数。
*/
class Solution {
public:
    int countSubMultisets(vector<int>& nums, int l, int r) {
        const int MOD = 1e9 + 7;
        int total = 0, cntZero = 0;
        map<int, int> cnt;
        for (int a : nums) {
            cnt[a]++;
            total += a;
        }

        cntZero = cnt[0];
        cnt.erase(0);
        if (total < l) {
            return 0;
        }
        r = min(r, total);

        vector<int> dp(r + 1);
        dp[0] = 1;

        for (auto &e : cnt) {
            int x = e.first, k = e.second;
            auto new_dp = dp;
            for (int j = x; j <= r; ++j) {
                new_dp[j] = (new_dp[j] + new_dp[j - x]) % MOD;
                if (j >= (k + 1) * x) {
                    new_dp[j] = (new_dp[j] - dp[j - (k + 1) * x] + MOD) % MOD;
                }
            }
            dp = new_dp;
        }

        int ans = 0;
        for (int i = l; i <= r; ++i) {
            ans = (ans + dp[i]) % MOD;
        }

        return 1ll * ans * (cntZero + 1) % MOD;
    }
};