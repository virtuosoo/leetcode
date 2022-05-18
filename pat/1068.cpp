#include <bits/stdc++.h>
using namespace std;
const int N = 10005, M = 105;

bool dp[N][M];
int n, m, a[N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + 1 + n);
    for(int i = 0; i <= n + 1; ++i) {
        dp[i][0] = true;
    }

    for (int i = n; i >= 1; --i) {
        for (int j = 0; j <= m; ++j) {
            dp[i][j] |= dp[i + 1][j];
            if (j >= a[i]) {
                dp[i][j] |= dp[i + 1][j - a[i]];
            }
        }
    }

    if (!dp[1][m]) {
        printf("No Solution\n");
        return 0;
    }

    int val = m;
    vector<int> ans;
    
    for (int i = 1; i <= n; ++i) {
        if (val >= a[i] && dp[i + 1][val - a[i]] && val > 0) {
            ans.push_back(a[i]);
            //printf("%d\n", a[i]);
            val -= a[i];
        }
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); ++i) {
        printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
    }
    return 0;
}