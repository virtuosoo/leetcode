#include <bits/stdc++.h>
using namespace std;
const int N = 105;

vector<int> g[N];
int n, m, id, k, res[N], dep[N], mdep;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &id, &k);
        for (int j = 1; j <= k; ++j) {
            int v;
            scanf("%d", &v);
            g[id].push_back(v);
        }
    }

    queue<int> q;
    q.push(1);
    dep[1] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        mdep = max(mdep, dep[u]);
        if (g[u].size() == 0) {
            res[dep[u]]++;
        }
        for(int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i];
            dep[v] = dep[u] + 1;
            q.push(v);
        }
    }
    for (int i = 0; i <= mdep; ++i) {
        printf("%d%c", res[i], i == mdep ? '\n' : ' ');
    }
    return 0;
}