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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = -1001;
        function<int(TreeNode *) > dfs = [&](TreeNode *u) {
            if (u == nullptr) {
                return -1001;
            }
            int tmp = u->val;
            int lmax = dfs(u->left), rmax = dfs(u->right);
            if (lmax > 0) {
                tmp += lmax;
            }
            if (rmax > 0) {
                tmp += rmax;
            }

            res = max(res, tmp);
            return max({u->val, u->val + lmax, u->val + rmax});
        };
        dfs(root);
        return res;
    }
};