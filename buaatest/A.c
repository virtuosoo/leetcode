#include <stdio.h>
#include <stdbool.h>
#define N 100005

char minHeap[] = "Min heap\n", maxHeap[] = "Max heap\n", notHeap[] = "Not a heap!\n";
int n, a[N];


bool isMinHeap(int u)
{
    bool res = true;
    if (2 * u <= n) {
        res &= a[u] <= a[2 * u];
        res &= isMinHeap(2 * u);
    }

    if (2 * u + 1 <= n) {
        res &= a[u] <= a[2 * u + 1];
        res &= isMinHeap(2 * u + 1);
    }
    return res;
}

bool isMaxHeap(int u)
{
    bool res = true;
    if (2 * u <= n) {
        res &= a[u] >= a[2 * u];
        res &= isMaxHeap(2 * u);
    }

    if (2 * u + 1 <= n) {
        res &= a[u] >= a[2 * u + 1];
        res &= isMaxHeap(2 * u + 1);
    }
    return res;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        if (isMinHeap(1)) {
            printf("%s", minHeap);
        } else if (isMaxHeap(1)) {
            printf("%s", maxHeap);
        } else {
            printf("%s", notHeap);
        }
    }
}