#include <stdio.h>
#include <stdbool.h>
#define N 1000005

int n, a[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }

    int t;
    while (~scanf("%d", &t)) {
        int pos = -1;
        for (int i = 1; i <= n; ++i) {
            if (a[i] == t) {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            puts("NO");
        } else {
            printf("%d\n", pos);
        }
    }
}