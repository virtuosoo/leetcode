#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    vector<Node *> children;
    pair<int, int> target;
    Node() {
        children.resize(26, NULL);
        target = {1e9, 1e9};
    }
};

class Trie {
public:
    Node *root;
    Trie() {
        root = new Node();
    }

    ~Trie() {
        remove(root);
    }

    void insert(string &s, int id) {
        int len = s.length();
        pair<int, int> newTarget = {len, id};
        Node *cur = root;
        for (char c : s) {
            int t = c - 'a';
            if (cur->children[t] == NULL) {
                cur->children[t] = new Node();
            }
            cur->target = min(cur->target, newTarget);
            cur = cur->children[t];
        }
        cur->target = min(cur->target, newTarget);
    }

    int find(string &s) { 
        Node *cur = root;
        for (char c : s) {
            int t = c - 'a';
            if (cur->children[t] == NULL) {
                break;
            }
            cur = cur->children[t];
        }
        return cur->target.second;
    }

    void remove(Node *cur) {
        for (Node *child : cur->children) {
            if (child != NULL) {
                remove(child);
            }
        }
        delete cur;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie trie = Trie();
        int n = wordsContainer.size(), m = wordsQuery.size();
        vector<int> ans(m);
        for (int i = 0; i < n; ++i) {
            reverse(wordsContainer[i].begin(), wordsContainer[i].end());
            trie.insert(wordsContainer[i], i);
        }

        //printf("%d %d\n", trie->root->target.first, trie->root->target.second);

        for (int i = 0; i < m; ++i) {
            reverse(wordsQuery[i].begin(), wordsQuery[i].end());
            ans[i] = trie.find(wordsQuery[i]);
        }
        return ans;
    }
};