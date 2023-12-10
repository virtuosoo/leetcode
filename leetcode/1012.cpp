#include <bits/stdc++.h>
using namespace std;


//数位dp，需要考虑前导0的影响, 例如n = 100, 当枚举到1时，不能算成有两个相同的0，肯定不对。
class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        int m = s.length();
        int dp[m][1<<10];
        memset(dp, -1, sizeof(dp));
        function<int(int, int, bool, bool)> f = [&](int i, int mask, bool limit, bool leadZero) {
            if (i == m) {
                return leadZero ? 0 : 1;
            }

            if (!limit && !leadZero && dp[i][mask] != -1) {
                return dp[i][mask];
            }

            int res = 0;
            if (leadZero) {
                res += f(i + 1, mask, false, true); //填前导0，不影响mask状态
            }

            int up = limit ? s[i] - '0' : 9;
            int d = leadZero ? 1 : 0;
            for (; d <= up; ++d) {
                if (((mask >> d) & 1) == 0) {
                    res += f(i + 1, mask | (1 << d), limit && d == up, false);
                }
            }
            if (!limit && !leadZero){
                dp[i][mask] = res;
            }
            return res;
        };
        return n - f(0, 0, true, true);
    }
};