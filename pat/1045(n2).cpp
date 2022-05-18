#include <bits/stdc++.h>
using namespace std;

const int N = 10005, M = 205;
int a[N], dp[N], n, m, l, favor[M], pos[M];
int cnt = 0;
int main()
{   
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &favor[i]);
        pos[favor[i]] = i;
    } 

    scanf("%d", &l);
    for (int i = 1; i <= l; ++i) {
        int x;
        scanf("%d", &x);
        if (pos[x] != 0) {
            a[++cnt] = pos[x];
        }
    }
    fill(dp, dp + 10005, 1);
    int ans = 0;
    for (int i = 1; i <= cnt; ++i) {
        for (int j = 1; j < i; ++j) {
            if (a[j] <= a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
    return 0;
}