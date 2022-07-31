import bisect

#并不是完美的离散化，例如[1, 5, 5, 10]只能离散化成[1, 2, 2, 4]
def discretization(l):
    res = []
    s = sorted(l)
    for a in l:
        res.append(bisect.bisect_left(s, a) + 1)
    return res

a = [1, 3, 3, 9]
print(discretization(a))