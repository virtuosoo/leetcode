from collections import defaultdict

tot = 0
mp = defaultdict(int)
g = [[] for i in range(100005)]
ans = 0

def addWord(word):
    global tot
    res = mp[word]
    if mp[word] == 0:
        tot += 1
        mp[word] = tot
        res = tot
    return res

def addEdge(rm, sm):
    u, v = addWord(rm), addWord(sm)
    g[u].append(v)

def dfs(u, dep):
    global ans
    ans = max(ans, dep)
    for v in g[u]:
        dfs(v, dep + 1)

n = int(input())

for i in range(n):
    s = input()
    rm, sm = s[3], s[4]
    addEdge(rm, sm)

rt = mp['SM0']
dfs(rt, 0)
print(ans)


