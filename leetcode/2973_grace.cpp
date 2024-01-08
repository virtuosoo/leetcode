#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n = edges.size() + 1;
        vector<int> g[n];
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<long long> ans(n);
        function<vector<int>(int, int)> dfs = [&](int u, int fa) {
            vector<int> res{cost[u]};
            for (int v : g[u]) {
                if (v != fa) {
                    auto a = dfs(v, u);
                    res.insert(res.end(), a.begin(), a.end());
                }
            }
            sort(res.begin(), res.end());
            int m = res.size();
            ans[u] = 1;
            if (m >= 3) {
                ans[u] = 1ll * res[m - 1] * res[m - 2] * res[m - 3];
                ans[u] = max(ans[u], 1ll * res[0] * res[1] * res[m - 1]);
                ans[u] = max(ans[u], 0ll);
            }

            if (m > 5) {
                res = {res[0], res[1], res[m - 1], res[m - 2], res[m - 3]};
            }
            return res;
        };
        dfs(0, -1);
        return ans;
    }
};