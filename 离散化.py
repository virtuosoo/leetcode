import bisect

def discretization(l: list) -> list:
    res = []
    s = sorted(l)
    for a in l:
        res.append(bisect.bisect_left(s, a) + 1)
    return res