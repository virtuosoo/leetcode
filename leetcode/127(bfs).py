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

        wordNum = 0
        wordId = dict()
        g = defaultdict(list)
        for word in wordList:
            addEdge(word)

        addEdge(beginWord)
        if endWord not in wordId:
            return 0
        beginId, endId = wordId[beginWord], wordId[endWord]
        dis = [int(1e9)] * (wordNum + 1)
        dis[beginId] = 0
        q = deque()
        q.append(beginId)
        while q:
            u = q.popleft()
            if u == endId:
                return dis[u] // 2 + 1
            for v in g[u]:
                if dis[v] == int(1e9):
                    dis[v] = dis[u] + 1
                    q.append(v)
        return 0
