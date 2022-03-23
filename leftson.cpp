#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
const int N = 100010;

vector<int> g[N];
int hmax[N], son[N], n, ans;

int dfs(int u)
{
    for(int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
        dfs(v);
    }
    for(int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
        hmax[u] = max(hmax[u], hmax[v] + son[u]);
    }
    ans = max(hmax[u], ans);
}
int main()
{
    scanf("%d", &n);
    for(int i = 2; i <= n; ++i){
        int u;
        scanf("%d", &u);
        g[u].push_back(i);
        son[u] += 1;
    }
    dfs(1);
    printf("%d\n", ans);

}