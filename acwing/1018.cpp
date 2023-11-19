#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int T, n;
int a;
int main()
{
    T = 1;
    while (T--) {
        scanf("%d", &n);
        vector<vector<int> > dp(n + 1, vector<int>(n + 1, INT_MAX));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                scanf("%d", &a);
                if (i == 1 && j == 1) {
                    dp[i][j] = a;
                }
                if (i > 1) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + a);
                }  
                if (j > 1) {
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + a);
                }
            }
        }
        printf("%d\n", dp[n][n]);
    }
}