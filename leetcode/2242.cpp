#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans;
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size();
        vector<pair<int, int> > g[n];

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            g[u].emplace_back(-scores[v], v);
        }
    }
};