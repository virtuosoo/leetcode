#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int MOD = 1e9 + 7;

//组合数模板
long long fac[N], fac_inv[N];

long long qpow(long long a, long long b)
{
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

auto init = [](){
    fac[0] = 1;
    for (int i = 1; i < N; ++i) {
        fac[i] = fac[i - 1] * i % MOD;
    }

    fac_inv[N - 1] = qpow(fac[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; --i) {
        fac_inv[i] = fac_inv[i + 1] * (i + 1) % MOD;
    }
    return 0;
}();

long long comb(int n, int k)
{
    return fac[n] * fac_inv[n - k] % MOD * fac_inv[k] % MOD;
}

class Solution {
public:
    int numberOfSequence(int n, vector<int>& sick) {
        int m = sick.size(), tot = 0;
        int s = n - m;
        long long res = 1;
        int pre = -1;
        for (int i = 0; i < m; ++i) {
            printf("%d\n", i);
            int len = sick[i] - pre - 1;
            res = res * comb(s, len) % MOD;
            s -= len;
            if (i != 0 && len > 0) {
                tot += len - 1;
            }

            pre = sick[i];
        }
        printf("tot : %d\n", tot);
        res = res * qpow (2, tot) % MOD;
        return res;
    }
};

int main()
{
    vector<int> sick = {0, 1};
    cout << Solution().numberOfSequence(5, sick);
}