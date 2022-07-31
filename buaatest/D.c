#include <stdio.h>
#define N 100005

int fa[N], n, m;

int find(int x)
{
    if (x == fa[x]) {
        return x;
    } else {
        return fa[x] = find(fa[x]);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }

    for (int i = 1; i <= m; ++i) {
        int op, u, v;
        scanf("%d%d%d", &op, &u, &v);
        if (op == 1) {
            int fu = find(u), fv = find(v);
            if (fu != fv) {
                fa[fu] = fv;
            }
        } else {
            int fu = find(u), fv = find(v);
            if (fu == fv) {
                puts("YES");
            } else {
                puts("NO");
            }
        }
    }
}