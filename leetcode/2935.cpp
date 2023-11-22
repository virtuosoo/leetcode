#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    vector<Node *> children;
    int cnt; //cnt表示从这个节点往下走，能到达多少个存在的数字节点
    Node() {
        children.resize(2, NULL);
        cnt = 0;
    }
};

class Trie {
public:
    const int HIGH_BIT = 21;
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
            cur->cnt++;
        }
    }

    void remove(int &val) {
        Node *cur = root;
        for (int i = HIGH_BIT; i >= 0; --i) {
            int t = (val >> i) & 1;
            cur = cur->children[t];
            cur->cnt--;
        }
    }

    int maxXor(int &val) { //找出树中寸的数，与val异或的最大值
        int res = 0;
        Node *cur = root;
        for (int i = HIGH_BIT; i >= 0; --i) {
            int t = (val >> i) & 1;
            if (cur->children[t^1] && cur->children[t^1]->cnt > 0) { //尽量往这个方向走
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
    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        Trie *trie = new Trie();
        int i = 0, j = 0;
        int res = 0;
        while (j < n) {
            trie->insert(nums[j]);
            while (i <= j && 2 * nums[i] < nums[j]) {
                trie->remove(nums[i]);
                i++;
            }
            res = max(res, trie->maxXor(nums[j]));
            j++;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5};
    printf("%d\n", s.maximumStrongPairXor(nums));
}