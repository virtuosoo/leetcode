#include <bits/stdc++.h>
using namespace std;

const int N = 15;
int dp[N][N][N][N];
int a[N][N];
int n;
int main()
{
    int i, j, val;
    scanf("%d", &n);
    while (1) {
        scanf("%d%d%d", &i, &j, &val);
        if (i == 0 && j == 0 && val == 0) {
            break;
        }
        a[i][j] = val;
    }
    for (int i1 = 1; i1 <= n; ++i1) {
        for (int j1 = 1;j1 <= n; ++j1) {
            for (int i2 = 1; i2 <= n; ++i2) {
                for (int j2 = 1; j2 <= n; ++j2) {
                    int &t = dp[i1][j1][i2][j2], add;
                    if (i1 == i2 && j1 == j2) {
                        t = add = a[i1][j1];
                    } else {
                        t = add = a[i1][j1] + a[i2][j2];
                    }

                    t = max(t, dp[i1 - 1][j1][i2 - 1][j2] + add);
                    t = max(t, dp[i1 - 1][j1][i2][j2 - 1] + add);
                    t = max(t, dp[i1][j1 - 1][i2 - 1][j2] + add);
                    t = max(t, dp[i1][j1 - 1][i2][j2 - 1] + add);
                }
            }
        }
    }
    printf("%d\n", dp[n][n][n][n]);
}