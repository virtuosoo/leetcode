#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int val[N], n, m, pre[N], maxVal[N], sPathNum[N], C1, C2;
vector<pair<int, int> > g[N];

void dijk(int src, int dest) {
    int dis[N];
    bool vis[N];
    for(int i = 0; i < n; ++i) {
        dis[i] = 1e9;
        vis[i] = false;
    }
    dis[src] = 0;
    sPathNum[src] = 1;
    maxVal[src] = val[src];
    priority_queue<pair<int, int> >q;
    q.push({0, src});

    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (vis[u]) {
            continue;
        }
        //cout << u << '\n';
        vis[u] = true;
        for(pair<int, int> edge : g[u]) {
            int v = edge.first, l = edge.second;
            if (dis[v] > dis[u] + l) {
                dis[v] = dis[u] + l;
                maxVal[v] = maxVal[u] + val[v];
                sPathNum[v] = sPathNum[u];
                q.push({-dis[v], v});
            } else if (dis[v] == dis[u] + l) {
                maxVal[v] = max(maxVal[v], maxVal[u] + val[v]);
                sPathNum[v] += sPathNum[u];
            }
        }
    }
    printf("%d %d\n", sPathNum[dest], maxVal[dest]);
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &C1, &C2);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &val[i]);
    }

    for(int i = 0; i < m; ++i) {
        int u, v, l;
        scanf("%d%d%d", &u, &v, &l);
        g[u].push_back({v, l});
        g[v].push_back({u, l});
    }

    dijk(C1, C2);
}