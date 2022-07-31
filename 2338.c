#include <stdlib.h>

#define N 10005
#define MX_PNUM 16

int numP[N][MX_PNUM];
long long C[N + MX_PNUM][MX_PNUM];
int MOD = 1e9 + 7;

int min(int a, int b)
{
    return a <= b ? a : b;
}

void init()
{
    C[0][0] = 1;
    for (int i = 1; i < N + MX_PNUM; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= min(i, MX_PNUM - 1); ++j) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }

    for (int i = 2; i < N; ++i) {
        int x = i;
        for (int p = 2; p * p <= x; ++p) {
            if (x % p == 0) {
                int k = 0;
                while (x % p == 0) {
                    k += 1;
                    x /= p;
                }
                numP[i][++numP[i][0]] = k;
            }
        }
        if (x > 1) numP[i][++numP[i][0]] = 1;
    }
}

int idealArrays(int n, int maxValue)
{
    init();
    long long ans = 0ll;
    for (int i = 1; i <= maxValue; ++i) {
        long long mul = 1ll;
        for (int j = 1; j <= numP[i][0]; ++j) {
            int k = numP[i][j];
            mul = mul * C[n + k - 1][k] % MOD;
            printf("%d %d %lld\n", j, k, C[n + k - 1][k]);
        }
        ans += mul;
    }
    return ans % MOD;
}