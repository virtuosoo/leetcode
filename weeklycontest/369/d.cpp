#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n = coins.size();
        vector<int> g[n];
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        auto dp = vector<vector<int> > (n, vector<int> (14, -1));
        function<int(int, int, int)> dfs = [&](int u, int fa, int t) {
            if (t >= 14) {
                return 0;
            }
            
            if (dp[u][t] != -1) {
                return dp[u][t];
            }

            int res1 = 0, res2 = 0;
            res1 += (coins[u] >> t) - k;
            res2 += (coins[u] >> (t + 1));
            for (int v : g[u]) {
                if (v != fa) {
                    res1 += dfs(v, u, t);
                    res2 += dfs(v, u, t + 1);
                }
            }
            return dp[u][t] = max(res1, res2);
        };
        return dfs(0, -1, 0);
    }
};