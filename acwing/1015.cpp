#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int T, R, C;
int a;
int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &R, &C);
        vector<vector<int> > dp(R + 1, vector<int>(C + 1, 0));
        for (int i = 1; i <= R; ++i) {
            for (int j = 1; j <= C; ++j) {
                scanf("%d", &a);
                dp[i][j] = a;
                if (i > 1) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + a);
                }  
                if (j > 1) {
                    dp[i][j] = max(dp[i][j], dp[i][j - 1] + a);
                }
            }
        }
        printf("%d\n", dp[R][C]);
    }
}