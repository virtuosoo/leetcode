#include <bits/stdc++.h>
using namespace std;

const int N = 10005, M = 205;
int a[N], dp[N], n, m, l, favor[M], pos[M];
int cnt = 0;

int lis(int *a, int len)
{
    vector<int> t;
    for (int i = 1; i <= len; ++i) {
        if (t.size() == 0) {
            t.push_back(a[i]);
            continue;
        }
        int pos = upper_bound(t.begin(), t.end(), a[i]) - t.begin();
        if (pos >= t.size()) {
            t.push_back(a[i]);
        } else {
            t[pos] = a[i];
        }
    }
    return t.size();
}
int main()
{   
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &favor[i]);
        pos[favor[i]] = i;
    } 

    scanf("%d", &l);
    for (int i = 1; i <= l; ++i) {
        int x;
        scanf("%d", &x);
        if (pos[x] != 0) {
            a[++cnt] = pos[x];
        }
    }
    int ans = lis(a, cnt);
    printf("%d\n", ans);
    return 0;
}