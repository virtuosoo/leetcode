#acwing 275 方格取数取两次
# f(k, x1, x2) 代表两次下标之和为k，横坐标分别为x1, x2的最大值


n, m = map(int, input().split())
dp = [[[0] * (n + 5) for i in range(n + 5)] for j in range(n + m + 5)]
g = [[]for i in range(n + 5)]

for i in range(1, n + 1):
    g[i] = [0] + list(map(int, input().split()))

ans = 0
for k in range(2, m + n + 1):
    for x1 in range(1, min(k, n + 1)):
        for x2 in range(1, min(k, n + 1)):
            if k - x1 > m or k - x2 > m:
                continue
            dp[k][x1][x2] = max(dp[k][x1][x2], dp[k - 1][x1][x2] + g[x1][k - x1] + g[x2][k - x2])
            dp[k][x1][x2] = max(dp[k][x1][x2], dp[k - 1][x1][x2 - 1] + g[x1][k - x1] + g[x2][k - x2])
            dp[k][x1][x2] = max(dp[k][x1][x2], dp[k - 1][x1 - 1][x2] + g[x1][k - x1] + g[x2][k - x2])
            dp[k][x1][x2] = max(dp[k][x1][x2], dp[k - 1][x1 - 1][x2 - 1] + g[x1][k - x1] + g[x2][k - x2])
            if x1 == x2:
                dp[k][x1][x2] -= g[x1][k - x1]
            ans = max(ans, dp[k][x1][x2])

print(ans)
