#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int m, n, k;
int a[N];
int main()
{
    scanf("%d%d%d", &m, &n, &k);
    for (int cas = 1; cas <= k; ++cas) {
        bool f = true;
        vector<int> stk;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        int tmp = 1;
        for (int i = 1; i <= n; ++i) {
            while (stk.size() == 0 || stk.back() != a[i]) {
                stk.push_back(tmp);
                tmp += 1;
                if (tmp > n) {
                    break;
                }
            }
            if (stk.size() > m || tmp > n + 1) {
                f = false;
                break;
            }
            if (stk.back() == a[i]) stk.pop_back();
            else {
                f = false;
                break;
            }
        }
        if (stk.size() != 0) f= false;
        puts(f ? "YES" : "NO");
    }
    return 0;
}