#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    vector<Node *> children;
    Node() {
        children.resize(2, NULL);
    }
};

class Trie {
public:
    const int HIGH_BIT = 30;
    Node *root;
    
    Trie() {
        root = new Node();
    }

    void insert(int &val) {
        Node *cur = root;
        for (int i = HIGH_BIT; i >= 0; --i) {
            int t = (val >> i) & 1;
            if (cur->children[t] == NULL) {
                cur->children[t] = new Node();
            }
            cur = cur->children[t];
        }
    }

    int maxXor(int &val) { //找出树中寸的数，与val异或的最大值
        int res = 0;
        Node *cur = root;
        for (int i = HIGH_BIT; i >= 0; --i) {
            int t = (val >> i) & 1;
            if (cur->children[t^1]) { //尽量往这个方向走
                res |= (1 << i);
                cur = cur->children[t^1];
            } else {
                cur = cur->children[t];
            }
        }
        return res;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        Trie trie{};
        int res = 0;
        for (int a : nums) {
            trie.insert(a);
            res = max(res, trie.maxXor(a));
        }
        return res;
    }
};