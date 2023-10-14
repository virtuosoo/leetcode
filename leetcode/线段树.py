N = 100005
sum = [0] * (N << 2)
add = [0] * (N << 2)
a = [0] * N 

def pushUp(rt):
    sum[rt] = sum[rt<<1] + sum[rt<<1|1]

def pushDown(rt, L, R):
    if add[rt] != 0:
        mid = (L + R) // 2
        sum[rt<<1] += (mid - L + 1) * add[rt]
        sum[rt<<1|1] += (R - mid) * add[rt]
        add[rt<<1] += add[rt]
        add[rt<<1|1] += add[rt]
        add[rt] = 0


def build(rt, L, R):
    if L == R:
        sum[rt] = a[L]
    else:
        mid = (L + R) // 2
        build(rt<<1, L, mid)
        build(rt<<1|1, mid + 1, R) 
        pushUp(rt)

def update(rt, L, R, ql, qr, val):
    if L >= ql and R <= qr:
        sum[rt] += (R - L + 1) * val
        add[rt] += val
        return
    pushDown(rt, L, R)
    mid = (L + R) // 2
    if mid >= ql:
        update(rt<<1, L, mid, ql, qr, val)
    if mid + 1 <= qr:
        update(rt<<1|1, mid + 1, R, ql, qr, val)
    pushUp(rt)

def query(rt, L, R, ql, qr):
    if L >= ql and R <= qr:
        return sum[rt]
    pushDown(rt, L, R)
    mid = (L + R) // 2
    res = 0
    if mid >= ql:
        res += query(rt<<1, L, mid, ql, qr)
    if mid + 1 <= qr:
        res += query(rt<<1|1, mid + 1, R, ql, qr)
    return res

n, m = map(int, input().split())
a = [0] + list(map(int, input().split()))
build(1, 1, n)

for i in range(m):
    q = list(map(int, input().split()))
    if len(q) == 4:
        update(1, 1, n, q[1], q[2], q[3])
    if len(q) == 3:
        print(query(1, 1, n, q[1], q[2]))