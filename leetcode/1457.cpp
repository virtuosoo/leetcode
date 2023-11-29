#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int res = 0;
        function<void(TreeNode*, int, int)> dfs = [&](TreeNode *u, int state, int dep) {
            state ^= (1 << u->val);
            if (u->left == nullptr && u->right == nullptr) {
                if (state == (state & (-state))) res++;  //个数全为偶数，或者只有一个是奇数
                return;
            };
            if (u->left) dfs(u->left, state, dep + 1);
            if (u->right) dfs(u->right, state, dep + 1);
        };
        dfs(root, 0, 1);
        return res;
    }
};