#include <bits/stdc++.h>
using namespace std;


// 枚举中间的边
class Solution {
public:
    int ans;
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size();
        vector<int> g[n];
        int res = -1;
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }

        for (int i = 0; i < n; ++i) {
            sort(g[i].begin(), g[i].end(), [&](const int a, const int b){
                return scores[a] > scores[b];
            }) ;
            if (g[i].size() > 3) {
                g[i].resize(3);
            }
        }

        for (auto &e : edges) {
            int x = e[0], y = e[1];
            for (auto &a : g[x]) {
                for (auto &b : g[y]) {
                    if (a != y && a != b && x != b) {
                        res = max(res, scores[x] + scores[y] + scores[a] + scores[b]);
                    }
                }
            }
        }
        return res;
    }
};