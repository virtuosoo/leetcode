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

        function<int(int, int, int)> dfs = [&](int u, int fa, int t) {
            
        };

    }
};