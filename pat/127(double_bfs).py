from collections import defaultdict
from collections import deque

class Solution:
    def ladderLength(self, beginWord, endWord, wordList):
        def addWord(word):
            nonlocal wordNum
            if word not in wordId:
                wordNum += 1
                wordId[word] = wordNum
            return wordId[word]
        def addEdge(word):
            u = addWord(word)
            chars = list(word)
            for i in range(len(chars)):
                tmp = chars[i]
                chars[i] = '*'
                w = "".join(chars)
                v = addWord(w)
                g[u].append(v)
                g[v].append(u)
                chars[i] = tmp
        def update(q:deque, cur, other):
            u = q.popleft()
            if other[u] != int(1e9):
                return (cur[u] + other[u]) // 2 + 1
            for v in g[u]:
                if cur[v] == int(1e9):
                    cur[v] = cur[u] + 1
                    q.append(v)
            return -1
        wordNum = 0
        wordId = dict()
        g = defaultdict(list)
        for word in wordList:
            addEdge(word)

        addEdge(beginWord)
        if endWord not in wordId:
            return 0
        beginId, endId = wordId[beginWord], wordId[endWord]
        beginDis, endDis = [int(1e9)] * (wordNum + 1), [int(1e9)] * (wordNum + 1)
        beginDis[beginId], endDis[endId] = 0, 0
        beginq, endq = deque(), deque()
        beginq.append(beginId)
        endq.append(endId)
        while beginq and endq:
            t = -1
            if len(beginq) < len(endq):
                t = update(beginq, beginDis, endDis)
            else:
                t = update(endq, endDis, beginDis)
            if t != -1:
                return t
        return 0
