#include <bits/stdc++.h>
using namespace std;

const int N = 10010;
int n, a[N];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }

    sort(a + 1, a + 1 + n);
    double ans = a[1];
    for (int i = 2; i <= n; ++i) {
        ans = (ans + a[i]) / 2;
    }
    printf("%d\n", int(ans));
    return 0;
}