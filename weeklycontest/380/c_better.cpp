#include <bits/stdc++.h>
using namespace std;

//二分答案，对每种答案数位dp算出价值
//更好的数位dp，在dfs过程中记录cnt，优化二分的上界
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
        int m = v.size();
        vector<vector<long long> > dp(m, vector<long long>(m + 1, -1));
        function<long long(int, int, bool)> dfs = [&](int idx, int cnt1, bool limit) -> long long {
            if (idx == -1) {
                return cnt1;
            }
            
            if (!limit && dp[idx][cnt1] != -1) {
                return dp[idx][cnt1];
            }
            
            int up = limit ? v[idx] : 1;
            long long res = 0;
            for (int d = 0; d <= up; ++d) {
                res += dfs(idx - 1, cnt1 + (d == 1 && (idx + 1) % t == 0), d == up && limit);
            }
            if (!limit) dp[idx][cnt1] = res;
            return res;
        };
        return dfs(m - 1, 0, true);
    }
};

int main()
{
    long long res = Solution().count(10, 2);
    printf("%lld\n", res);
}