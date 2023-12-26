#include <bits/stdc++.h>
using namespace std;


//并查集
class UnionFind {
public:
    vector<int> fa;

    UnionFind(int n): fa(n) {
        for (int i = 0; i < n; ++i) {
            fa[i] = i;
        }
    }

    int find(int x) {
        if (x != fa[x]) {
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }

    void merge(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX != rootY) {
            fa[rootX] = rootY;
        }
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        UnionFind uf(n);

        for (vector<int> &p : pairs) {
            int x = p[0], y = p[1];
            uf.merge(x, y);
        }

        map<int, priority_queue<char, vector<char>, greater<char>> *> mp;
        for (int i = 0; i < n; ++i) {
            int root = uf.find(i);
            if (mp.find(root) == mp.end()) {
                mp[root] = new priority_queue<char, vector<char>, greater<char>>();
                mp[root]->push(s[i]);
            } else {
                mp[root]->push(s[i]);
            }
        }

        string res(n, '#');
        for (int i = 0; i < n; ++i) {
            int root = uf.find(i);
            res[i] = mp[root]->top();
            mp[root]->pop();
        }
        return res;
    }
};