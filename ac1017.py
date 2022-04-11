import bisect
def LIS(nums):
    a = []
    for num in nums:
        pos = bisect.bisect_left(a, num)
        if pos == len(a):
            a.append(num)
        else:
            a[pos] = num
    return len(a)

k = int(input())
for case in range(k):
    n = int(input())
    nums = list(map(int, input().split()))
    ans = max(LIS(nums), LIS(nums[::-1]))
    print(ans)
