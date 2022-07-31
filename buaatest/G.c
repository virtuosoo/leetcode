#include <stdio.h>
#include <stdbool.h>
#define N 5000005
#define ll long long

ll pow2[30], MOD = 1000007, dp[N];
bool isPowerOf2[N];
ll n;
int main()
{
    pow2[0] = 1;
    isPowerOf2[1] = true;
    for (int i = 1; i <= 29; ++i) {
        pow2[i] = pow2[i - 1] * 2;
        if (pow2[i] > N) {
            break;
        }
        isPowerOf2[pow2[i]] = true; 
    }

    dp[0] = 1;
    scanf("%lld", &n);
    for (int i = 0; i <= 22; ++i) {
        for (int j = pow2[i]; j <= n; ++j) {
            dp[j] = (dp[j] + dp[j - pow2[i]]) % MOD;
        }
    }
    printf("%lld\n", dp[n]);
}