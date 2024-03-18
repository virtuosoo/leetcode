#include <bits/stdc++.h>
using namespace std;

vector<int> mul(vector<int> &a, vector<int> &b)
{
    int n = a.size(), m = b.size();
    vector<int> c(n + m, 0);
    for (int i = 0; i < n + m; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j < n && i - j < m) {
                c[i] += a[j] * b[i - j];
            }
        }
        if (c[i] >= 10) {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
    }
    return c;
}

int main()
{
    vector<int> a, b;
    string sa, sb;
    cin >> sa >> sb;
    
    for (int i = sa.length() - 1; i >= 0; --i) {
        a.push_back(sa[i] - '0');
    }

    for (int i = sb.length() - 1; i >= 0; --i) {
        b.push_back(sb[i] - '0');
    }

    vector<int> res = mul(a, b);
    int i;
    for (i = res.size() - 1; i >= 0; --i) {
        if (res[i] != 0) break;
    }
    
    if (i == -1) {
        printf("0");
    }

    for (; i >= 0; --i) {
        printf("%d", res[i]);
    }
    return 0;
}