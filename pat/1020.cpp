#include <bits/stdc++.h>
using namespace std;

const int N = 35;
int n, post[N], in[N];
vector<int> g[N];

int getTree(int pl, int pr, int il, int ir)
{
    if (pl > pr || il > ir) {
        return -1;
    }
    int rt = post[pr]; //根节点一定是后序的最后一个
    int mid = -1;
    for (int i = il; i <= ir ; ++i) {
        if (in[i] == rt) {
            mid = i;
            break;
        }
    }
    int lTreeSize = mid - il, rTreeSize = ir - mid;
    int lson = -1, rson = -1;
    if (lTreeSize > 0) {
        lson = getTree(pl, pl + lTreeSize - 1, il, mid - 1);
    }
    if (rTreeSize > 0) {
        rson = getTree(pl + lTreeSize, pr - 1, mid + 1, ir);
    }

    if (lson != -1) {
        g[rt].push_back(lson);
    }
    if (rson != -1) {
        g[rt].push_back(rson);
    }
    return rt;
}
int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &post[i]);
    for(int i = 1; i <= n; ++i) scanf("%d", &in[i]);
    int root = getTree(1, n, 1, n);
    queue<int> q;
    vector<int> ans;
    q.push(root);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for(int v : g[u]) {
            q.push(v);
        }
    }

    for (int i = 0; i < ans.size(); ++i) {
        printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
    }
    return 0;
}