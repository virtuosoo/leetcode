#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n, k;
int a[N];
long long dp[N];

int main()
{
    long long sum = 0, t = LLONG_MAX;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    deque<int> q;
    for (int i = 1; i <= n; ++i) {
        if (i <= k + 1) {
            dp[i] = a[i];
        } else {
            dp[i] = dp[q.front()] + a[i];
        }
        //printf("%d %lld\n", i, dp[i]);
        if (!q.empty() && i - q.front() >= k + 1) {
            q.pop_front();
        }
        while (!q.empty() && dp[i] < dp[q.back()]) {
            q.pop_back();
        }
        q.push_back(i);
    }

    for (int i = n - k; i <= n; ++i) {
        t = min(t, dp[i]);
    }
    printf("%lld\n", sum - t);
}