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
        function<void(int, int, vector<int>&, vector<int> &)> dfs = [&](int u, int fa, vector<int> &posOut, vector<int> &negOut) {
            priority_queue<int, vector<int>, greater<>> qpos;
            priority_queue<int> qneg;

            if (cost[u] > 0) qpos.push(cost[u]);
            else qneg.push(cost[u]);

            for (int v : g[u]) {
                if (v != fa) {
                    vector<int> pos, neg;
                    dfs(v, u, pos, neg);
                    for (int a : pos) {
                        qpos.push(a);
                    }

                    for (int a : neg) {
                        qneg.push(a);
                    }

                    while (qpos.size() > 3) {
                        qpos.pop();
                    }

                    while (qneg.size() > 3) {
                        qneg.pop();
                    }
                }
            }
            while (!qpos.empty()) {
                posOut.push_back(qpos.top());
                qpos.pop();
            }

            while (!qneg.empty()) {
                negOut.push_back(qneg.top());
                qneg.pop();
            }

            sort(posOut.begin(), posOut.end(), greater<int>());
            sort(negOut.begin(), negOut.end());
            
            ans[u] = 0;
            if (posOut.size() + negOut.size() < 3) {
                ans[u] = 1;
            } else {
                if (posOut.size() == 3) {
                    ans[u] = 1ll * posOut[0] * posOut[1] * posOut[2];
                }

                if (negOut.size() >= 2 && posOut.size() >= 1) {
                    ans[u] = max(ans[u], 1ll * posOut[0] * negOut[0] * negOut[1]);
                }
            }
        };
        vector<int> pos, neg;
        dfs(0, -1, pos, neg);
        return ans;
    }
};