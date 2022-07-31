#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int a[N];
vector<int> prime;
int myhash[N];
bool vis[N];

int mSize, n;
void getPrime(int maxn)
{
    for (int i = 2; i < maxn; ++i) {
        if (!vis[i]) {
            prime.push_back(i);
        }
        for (int p : prime) {
            if (p * i >= maxn) break;
            vis[p * i] = true;
            if (i % p == 0) break;
        }
    }
}
int main()
{
    getPrime(N);
    scanf("%d%d", &mSize, &n);
    int size;
    for(int i = mSize; i < N; ++i) {
        if (!vis[i]) {
            size = i;
            break;
        }
    }
    if (mSize <= 1) {
        size = 2;
    }
    for (int i = 1; i <= n; ++i) {
        int a, f = -1;
        scanf("%d", &a);
        for (int step = 0; step < size; ++step) {
            if (myhash[(a + step * step) % size] == 0) {
                f = (a + step * step) % size;
                myhash[(a + step * step) % size] = 1;
                break;
            }
        }
        if (f == -1) printf("-");
        else printf("%d", f);
        printf("%c", i == n ? '\n' : ' ');
    }
    return 0;
}