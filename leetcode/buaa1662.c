#include <stdio.h>
#include <string.h>
#define N 6005

int n, val[N], dp[N][2], indegree[N];

struct edge {
    int to, next;
}g[N];
int cnt = -1, head[N];

int max(int a, int b)
{
    return a > b ? a : b;
}

void add(int u, int v)
{
    cnt++;
    g[cnt].next = head[u];
    g[cnt].to = v;
    head[u] = cnt;
}

void dfs(int u)
{
    dp[u][1] = val[u];
    dp[u][0] = 0;
    for (int i = head[u]; i != -1; i = g[i].next) {
        int v = g[i].to;
        dfs(v);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}

int main()
{
    memset(head, -1, sizeof(head));
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &val[i]);
    }

    for (;;) {
        int L, K;
        scanf("%d %d", &L, &K);
        if (L == 0 && K == 0) {
            break;
        }
        add(K, L);
        indegree[L]++;
    }

    int rt = 0;
    for(int i = 1; i <= n; ++i) {
        if (indegree[i] == 0) {
            rt = i;
            break;
        }
    }
    dfs(rt);
    printf("%d\n", max(dp[rt][0], dp[rt][1]));
}