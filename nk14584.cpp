#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e8 + 7;
int main()
{
    int T, n, k;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        long long a = 1ll * k, b = 1ll * k * (k - 1), c;
        for (int i = 3; i <= n; ++i) {
            if (i == 3) {
                c = (k - 2) * b % MOD;
            } else {
                c = ((k - 1) * a + (k - 2) * b) % MOD;
            }
            a = b;
            b = c;
        }
        printf("%lld\n", c);
    }
}