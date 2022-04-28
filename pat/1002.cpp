#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
double p1[N], p2[N];
int np1, np2;

int main()
{
    scanf("%d", &np1);
    for(int i = 1; i <= np1; ++i) {
        int exp; double coe;
        scanf("%d%lf", &exp, &coe);
        p1[exp] = coe;
    }

    scanf("%d", &np2);
    for(int i = 1; i <= np2; ++i) {
        int exp; double coe;
        scanf("%d%lf", &exp, &coe);
        p2[exp] = coe;
    }

    int num = 0, m = 1005;
    for(int i = 0; i <= 1000; ++i) {
        p1[i] += p2[i];
        if (abs(p1[i]) > 1e-8) {
            num += 1;
            m = min(i, m);
        }
    }
    
    if (num == 0) {
        printf("%d", num);
        return 0;
    }

    printf("%d ", num);
    for(int i = 1000; i >=0; --i) {
        if (abs(p1[i]) > 1e-8) {
            printf("%d %.1lf", i, p1[i]);
            if (i != m) {
                printf(" ");
            }
        }
    }
}