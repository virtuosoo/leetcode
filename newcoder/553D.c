#include<stdio.h>
#define N 1000005
int n, m;
const int MOD = 1e9 + 7;
long long C1[N], C2[N];

long long qpow(long long a, long long b)
{
    long long res = 1ll;
    while (b) {
        if (b & 1) res = res * a % MOD;
        b /= 2;
        a = a * a % MOD;
    }
    return res;
}
int main()
{
    scanf("%d%d", &m, &n);
    C1[0] = 1;
    for (int i = 1; i <= m - 1; ++i) {
        C1[i] = (long long) C1[i - 1] * (n - 1 - i + 1) % MOD * qpow(i, MOD - 2) % MOD;
    }

    C2[0] = 1;
    for (int i = 1; i <= n; ++i) {
        C2[i] = (long long) C2[i - 1] * (n + m - 1 - i + 1) % MOD * qpow(i, MOD - 2) % MOD;
    }
    printf("%lld %lld\n",C1[m - 1], C2[n]);
}