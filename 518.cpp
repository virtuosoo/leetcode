#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int> > dp(n + 1);
        for (int i = 0; i <= n; ++i) {
            dp[i].resize(amount + 1);
        }
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= amount; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j - coins[i - 1] >= 0) {
                    dp[i][j] += dp[i - 1][j - coins[i - 1]];
                }
                printf("%d %d %d\n", i, j, dp[i][j]);
            }
        }
        return dp[n][amount];

    }
};

int main()
{
    vector<int> coins{1, 2, 5};
    Solution a;
    cout << a.change(5, coins);

}