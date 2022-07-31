#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans = -1;

    void dfs(int u, int dep, vector<bool> &vis, vector<int> *g) {
        ans = max(ans, dep);
        vis[u] = true;
        for (int &v: g[u]) {
            if (!vis[v])
                dfs(v, dep + 1, vis, g);
        }
    }

    int longestCycle(vector<int>& edges) {
        ans = -1;
        int n = edges.size();
        const int nn = n;
        vector<int> g[nn], inDegree(n);
        vector<bool> notInCycle(n), vis(n);

        for (int i = 0; i < n; ++i) {
            if (edges[i] != -1) {
                g[i].push_back(edges[i]);
                inDegree[edges[i]] += 1;
            }
        }
        queue<int> q;   
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            int u = q.front();
            notInCycle[u] = true;
            q.pop();
            for (int &v : g[u]) {
                --inDegree[v];
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (notInCycle[i] == false && vis[i] == false) {
                dfs(i, 1, vis, g);
            }
        }
        return ans;

    }
};