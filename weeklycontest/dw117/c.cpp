#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// 容斥原理
class Solution {
public:
    int stringCount(int n) {
        long long x = 1, total = qpow(26, n);
        if (n <= 3) {
            return 0;
        }
        x = qpow(25, n) * 2 % MOD;
        x = (x + qpow(25, n)) % MOD;
        x = (x + qpow(25, n - 1) * n) % MOD;
        x = (x - qpow(24, n) + MOD) % MOD;
        x = (x - 2 * qpow(24, n) + MOD) % MOD;
        x = (x - 2 * qpow(24, n - 1) * n + MOD) % MOD;
        x = (x + qpow(23, n) + qpow(23, n - 1) * n) % MOD;
        long long res = (total - x + MOD) % MOD;
        return int(res);
    }

    long long qpow(int a, int b) {
        int res = 1;
        while (b) {
            if (b & 1) {
                res = 1ll * a * res % MOD;
            }
            b >>= 1;
            a = 1ll * a * a % MOD;
        }
        return res;
    }
};