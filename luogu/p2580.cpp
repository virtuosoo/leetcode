#include <bits/stdc++.h>
using namespace std;

// 动态生成节点的trie模板
class Node {
public:
    vector<Node *> children;
    bool is_word;
    int cnt;
    Node() {
        children.resize(26, NULL);
        is_word = false;
        cnt = 0;
    }
};

class Trie {
public:
    Node *root;
    Trie() {
        root = new Node();
    }

    void insert(string &s) {
        Node *cur = root;
        for (char c : s) {
            int t = c - 'a';
            if (cur->children[t] == NULL) {
                cur->children[t] = new Node();
            }
            cur = cur->children[t];
        }
        cur->is_word = true;
    }

    int find(string &s) { 
        Node *cur = root;
        for (char c : s) {
            int t = c - 'a';
            if (cur->children[t] == NULL) {
                return -1;
            }
            cur = cur->children[t];
        }
        if (!cur->is_word) {
            return -1;
        }
        cur->cnt++;
        return cur->cnt;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    string w;
    Trie *trie = new Trie();
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> w;
        trie->insert(w);
    }
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> w;
        int res = trie->find(w);
        if (res == -1) {
            cout << "WRONG\n";
        } else if (res == 1) {
            cout << "OK\n";
        } else if (res > 1) {
            cout << "REPEAT\n";
        }
    }
}