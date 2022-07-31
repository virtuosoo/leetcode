#include <stdio.h>

#define N 205

int a[N][N], l[N][N], r[N][N], t[N][N], b[N][N];
int n, m;

int max(int a, int b)
{
    return a >= b ? a : b;
}

int min(int a, int b)
{
    return a <= b ? a : b;
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &a[i][j]);
            l[i][j] = max(l[i][j - 1], a[i][j]);
            t[i][j] = max(t[i - 1][j], a[i][j]);
        }
    }
    int ans = 0;
    for (int i = n; i >= 1; --i) {
        for (int j = m; j >= 1; --j) {
            r[i][j] = max(r[i][j + 1], a[i][j]);
            b[i][j] = max(b[i + 1][j], a[i][j]);
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int tmp = min(l[i][j], min(t[i][j], min(r[i][j], b[i][j])));
            ans += tmp - a[i][j];
            printf("%d ", tmp);
        }
        printf("\n");
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            printf("%d %d: l(%d), r(%d), t(%d), b(%d)\n", i, j, l[i][j], r[i][j], t[i][j], b[i][j]);
        }
    }

    printf("%d", ans);
}