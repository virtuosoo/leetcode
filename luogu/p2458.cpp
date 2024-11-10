#include <bits/stdc++.h>
using namespace std;

const int N = 1505;

int n;
int val[N];
int dp[N][3];
vector<int> g[N];

void dfs(int u, int fa) {
    int minn = 1e9;
    for (int v : g[u]) {
        if (v != fa) {
            dfs(v, u);
            dp[u][0] += min(dp[v][0], dp[v][1]);
            dp[u][1] += min(dp[v][0], dp[v][2]);
            minn = min(minn, dp[v][0] - dp[v][2]);   
        }
    }

    if (g[u].size() != 1) {
        dp[u][2] = dp[u][1];
        if (minn != (int) 1e9 && minn > 0) {
            dp[u][2] += minn;
        }
    }
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        int u, k, m;
        cin >> u >> k >> m;
        val[u] = k;

        for (int j = 1; j <= m; ++j) {
            int v;
            cin >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }

    for (int i = 1; i <= n; ++i) {
        dp[i][0] = val[i];
        dp[i][1] = 0;
        dp[i][2] = 1e9;
    }

    dfs(1, -1);
    cout << min(dp[1][0], dp[1][2]) << '\n';
}