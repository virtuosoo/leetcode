#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        vector<int> g[n];
        vector<long long> sum(n), dp(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        function<long long(int, int)> dfsSum = [&](int u, int fa) {
            sum[u] = values[u];
            for (int v : g[u]) {
                if (v != fa) {
                    sum[u] += dfsSum(v, u);
                }
            }
            return sum[u];
        };
        dfsSum(0, -1);

        function<long long(int, int)> dfsDp = [&](int u, int fa) {
            if (u != 0 && g[u].size() == 1) {
                return 0ll;
            }

            dp[u] = sum[u] - values[u];
            long long tmp = values[u];
            for (int v : g[u]) {
                if (v != fa) {
                    tmp += dfsDp(v, u);
                }
            }
            dp[u] = max(dp[u], tmp);
            return dp[u];
        };
        return dfsDp(0, -1);
    }
};