T = int(input())

for test in range(T):
    r, c = map(int, input().split())
    g = [[] for i in range(r)]
    dp = [[0] * c for i in range(r)]
    for i in range(r):
        g[i] = list(map(int, input().split()))
    
    ans = 0
    for i in range(r):
        for j in range(c):
            dp[i][j] = g[i][j]
            if i > 0:
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + g[i][j])
            if j > 0:
                dp[i][j] = max(dp[i][j], dp[i][j - 1] + g[i][j])
            ans = max(ans, dp[i][j])

    print(ans)
    
