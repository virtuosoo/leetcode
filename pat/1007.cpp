#include <bits/stdc++.h>
using namespace std;
const int N = 10005;

int n;
long long dp[N], a[N];
bool allNeg = true;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        allNeg &= (a[i] < 0);
    }

    if (allNeg) {
        printf("%d %lld %lld\n", 0, a[1], a[n]);
        return 0;
    }

    int maxsum = 0, l = 0, r = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i] = max(dp[i - 1] + a[i], a[i]);
        if (maxsum < dp[i]) {
            maxsum = dp[i];
            r = i;
        }
    }
    l = r;
    for (int i = r; i >= 2; i--) {
        if (dp[i - 1] + a[i] == dp[i]) {
            l = i - 1;
        } else {
            break;
        }
    }
    printf("%d %lld %lld\n", maxsum, a[l], a[r]);
    return 0; 
}