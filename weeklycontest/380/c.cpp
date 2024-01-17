#include <bits/stdc++.h>
using namespace std;

//二分答案，对每种答案数位dp算出价值
class Solution {
public:
    long long findMaximumNumber(long long k, int x) {
        long long l = 1, r = 1e15;
        while (l < r) {
            long long mid = (l + r + 1) / 2;
            if (count(mid, x) <= k) l = mid;
            else r = mid - 1;
        }
        return l;
    }

    long long count(long long x, int t) {
        vector<int> v;
        while (x) {
            v.push_back(x & 1);
            x >>= 1;
        } 
        vector<long long> sum(v.size());
        sum[0] = v[0];
        for (int i = 1; i < v.size(); ++i) {
            sum[i] = sum[i - 1];
            if (v[i] == 1) {
                sum[i] += (1ll << i);
            }
        }
        vector<long long> dp(v.size(), -1);
        function<long long(int, bool)> dfs = [&](int idx, bool limit) -> long long {
            if (!limit && dp[idx] != -1) {
                return dp[idx];
            }
            int up = limit ? v[idx] : 1;
            if (idx == 0) {
                if (t == 1 && up == 1) return 1;
                return 0;
            }
            long long res = 0;
            for (int d = 0; d <= up; ++d) {
                res += dfs(idx - 1, limit && d == up);
                if (d == 1 && (idx + 1) % t == 0) {
                    if (limit) res += sum[idx - 1] + 1;
                    else res += (1ll << idx);
                }
            }
            if (!limit) dp[idx] = res;
            return res;
        };
        return dfs(v.size() - 1, true);
    }
};

int main()
{
    long long res = Solution().count(10, 2);
    printf("%lld\n", res);
}