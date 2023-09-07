#include <bits/stdc++.h>
using namespace std;

//倍增lca
class Solution {
public:
    vector<vector<pair<int, int> > > g;
    int fa[10005][18];
    int dep[10005];
    int lg2[10005];
    int cnt[10005][18][26];

    Solution() {
        for (int i = 2; i <= 10000; ++i) {
            lg2[i] = lg2[i >> 1] + 1;
        }
    }

    vector<int> minOperationsQueries(int n, vector<vector<int> >& edges, vector<vector<int> >& queries) {
        g = vector<vector<pair<int, int> > >(n);
        memset(fa, -1, sizeof(fa));
        memset(cnt, 0, sizeof(cnt));
        memset(dep, 0, sizeof(dep));
        vector<int> res;
        for (auto & e : edges) {
            int u = e[0], v = e[1], w = e[2] - 1;
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
        //printf("dfs start\n");
        dfs(0, -1, -1);
        //printf("dfs finish\n");
        for (auto & q : queries) {
            int x = q[0], y = q[1];
            vector<int> sum(26);
            int totlen = 0;

            if (dep[x] < dep[y]) {
                swap(x, y);  //假定x在下面
            }

            totlen += dep[x] - dep[y];
            while (dep[x] > dep[y]) {
                int jmp = lg2[dep[x] - dep[y]];
                for (int w = 0; w < 26; ++w) {
                    sum[w] += cnt[x][jmp][w];
                }
                //printf("debug1 sum[4] %d\n", sum[4]);
                x = fa[x][jmp];
            }

            if (x != y) {
                for (int k = lg2[dep[x]]; k >= 0; --k) {
                    if (fa[x][k] != fa[y][k]) {
                        totlen += 2 * (1 << k);
                        for (int w = 0; w < 26; ++w) {
                            sum[w] += cnt[x][k][w] + cnt[y][k][w];
                        }
                        x = fa[x][k];
                        y = fa[y][k];
                    }
                }
                totlen += 2;
                for (int w = 0; w < 26; ++w) {
                    sum[w] += cnt[x][0][w] + cnt[y][0][w];
                }
            }

            //printf("tot %d\n", totlen);
            int mx = 0;
            for (int w = 0; w < 26; ++w) {
                //printf("w %d, sum %d\n", w, sum[w]);
                mx = max(mx, sum[w]);
            }
            res.push_back(totlen - mx);
        }
        return res;
    }

    void dfs(int u, int f, int w) {
        fa[u][0] = f;
        if (f == -1) {
            dep[u] = 0;
        } else {
            dep[u] = dep[f] + 1;
        }
        //printf("u %d dep %d log %d\n", u, dep[u], lg2[dep[u]]);
        for (int i = 1; i <= lg2[dep[u]]; ++i) {
            //printf("u %d i %d mid %d fa %d\n", u, i, fa[u][i - 1], fa[fa[u][i - 1]][i - 1]);
            int mid = fa[u][i - 1];
            fa[u][i] = fa[mid][i - 1];
        }

        if (f != -1) {
            cnt[u][0][w] = 1;
            for (int i = 1; i <= lg2[dep[u]]; ++i) {
                for (int w = 0; w < 26; ++w) {
                    int mid = fa[u][i - 1];
                    cnt[u][i][w] = cnt[u][i - 1][w] + cnt[mid][i - 1][w];
                }
            }
        }

        for (auto &e : g[u]) {
            int v = e.first, nw = e.second;
            if (v != f) {
                dfs(v, u, nw);
            }
        }
    }
};

int main()
{
    int n = 6;
    vector<vector<int> > edges{{4, 1, 3}, {2, 4, 4}, {5, 2, 5}, {3, 1, 5}, {0, 4, 2}};
    vector<vector<int> > q{{5, 3}};
    Solution *s = new Solution();
    vector<int> res = s->minOperationsQueries(n, edges, q);
    for (int a : res) {
        printf("%d ", a);
    }
}