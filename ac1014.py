n = int(input())
a = [0] + list(map(int, input().split()))

f1, f2 =  [1] * (n + 5), [1] * (n + 5)

for i in range(1, n + 1):
    for j in range(1, i):
        if a[j] < a[i]:
            f1[i] = max(f1[i], f1[j] + 1)

for i in range(n, 0, -1):
    for j in range(n, i, -1):
        if a[j] < a[i]:
            f2[i] = max(f2[i], f2[j] + 1)

ans = 0
for i in range(1, n + 1):
    ans = max(ans, f1[i] + f2[i] - 1)
print(ans)
