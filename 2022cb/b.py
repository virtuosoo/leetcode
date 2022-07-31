import datetime
from operator import truediv

start = datetime.date(2022, 1, 1)
delta = datetime.timedelta(days=1)
end = datetime.date(2023, 1, 1)

now = start
cnt = 0

def check(now):
    s = str(now.year) + str(now.month) + str(now.day)
    li = list(map(int, s))
    if now.month < 10:
        li.insert(4, 0)
    if now.day < 10:
        li.insert(6, 0)

    for i in range(6):
        if li[i] + 1 == li[i + 1] and li[i] + 2 == li[i + 2]:
            return True
    return False


check(start)
    

while now != end:
    if check(now):
        cnt += 1
    now += delta
print(cnt)

