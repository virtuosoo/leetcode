#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        vector<int> g[n], inDegree(n), removed(n);

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
            inDegree[u]++;
            inDegree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (coins[i] == 0 && inDegree[i] == 1) {
                q.push(i);
            }
        }

        // 拓补排序，去除没有coin的叶子节点
        while (!q.empty()) {
            int u = q.front();
            removed[u] = 1;
            q.pop();
            for (int v : g[u]) {
                inDegree[v]--;
                if (inDegree[v] == 1 && coins[v] == 0) {
                    q.push(v);
                }
            }
        }

        // 此时所有叶子节点都有coin，再去除最外面两层
        for (int a = 0; a < 2; ++a) {
            for (int i = 0; i < n; ++i) {
                if (inDegree[i] == 1 && removed[i] == 0) {
                    q.push(i);
                }
            }
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                removed[u] = 1;
                for (int v : g[u]) {
                    inDegree[v]--;
                }
            }
        }

        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (removed[i] == 0) sum++;
        }
        if (sum == 0) return 0;
        return 2 * (sum - 1);
    }
};