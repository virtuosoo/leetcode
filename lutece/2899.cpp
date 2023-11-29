#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
char s[N];
int n;
int main()
{
    scanf("%d", &n);
    scanf("%s", s + 1);
    int c = 0;
    for (int i = 1; i <= n - 1; ++i) {
        if (s[i] == '1') {
            c++;
        }
    }
    printf("1 %d\n", c + 1);
}