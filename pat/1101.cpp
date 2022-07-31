#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int a[N], n;
bool ok[N];

int main()
{
    scanf("%d", &n);
    int lmax = -1, rmin = 1e9 + 1;
    for (int i = 1; i <= n; ++i) {
        ok[i] = true;
    }

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] < lmax) {
            ok[i] = false;
        }
        lmax = max(lmax, a[i]);
    }
    for (int i = n; i >= 1; --i) {
        if (a[i] > rmin) {
            ok[i] = false;
        }
        rmin = min(rmin, a[i]);
    }
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        if (ok[i]) {
            ans.push_back(a[i]);
        }
    }
    printf("%lu\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
    }
    if (ans.size() == 0){
        printf("\n");
    }
    return 0;
}