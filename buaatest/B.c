#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 500005

int n, m;
char notFound[] = "Not Found";
char q[30];

struct record
{
    char name[30];
    char number[30];
}a[N];

size_t min(size_t a, size_t b)
{
    return a > b ? b : a;
}

int cmp(const void *a, const void *b)
{
    struct record* ta = (struct record*) a;
    struct record* tb = (struct record*) b;
    size_t lena = strlen(ta->name), lenb = strlen(tb->name);
    for (int i = 0; i < min(lena, lenb); ++i) {
        if (ta->name[i] != tb->name[i]) {
            return ta->name[i] - tb->name[i];
        }
    }
    if (lena > lenb) {
        return 1;
    } else if (lena < lenb) {
        return -1;
    } else {
        return 0;
    }
}

int search(char *q)
{
    int l = 1, r = n;
    struct record temp;
    strcpy(temp.name, q);
    while (l < r) {
        int mid = (l + r) / 2;
        if (cmp(&a[mid], &temp) >= 0) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1;  i <= n; ++i) {
        scanf("%s%s", a[i].name, a[i].number);
    }

    qsort(a + 1, n, sizeof(struct record), cmp);

    for (int i = 1; i <= m; ++i) {
        scanf("%s", q);
        int l = search(q);
        if (strcmp(a[l].name, q) == 0) {
            puts(a[l].number);
        } else {
            puts(notFound);
        }
    }
}