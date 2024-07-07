#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        map<TreeNode*, int> deps;
        map<TreeNode*, TreeNode*> parent;
        function<void(TreeNode*, int, TreeNode*)> findDep = [&](TreeNode *u, int dep, TreeNode *pa) {
            if (u == nullptr) {
                return;
            }
            parent[u] = pa;
            deps[u] = dep;
            findDep(u->left, dep + 1, u);
            findDep(u->right, dep + 1, u);
        };
        findDep(root, 0, nullptr);
        if (deps[p] < deps[q]) { //假定p的深度更深。
            swap(p, q);
        }
        while (deps[p] > deps[q]) {
            p = parent[p];
        }
        while (p != q) {
            p = parent[p];
            q = parent[q];
        }
        return p;
    }
};