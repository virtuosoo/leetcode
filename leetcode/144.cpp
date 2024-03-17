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

struct Frame {
    TreeNode *u;
    int pc;
};

vector<Frame> stk;

#define call(u) ({stk.push_back(Frame{(u), -1});})
#define ret() ({stk.pop_back();})

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        call(root);
        while (!stk.empty()) {
            Frame &f = stk.back();
            f.pc++;
            switch (f.pc) {
            case 0:
                if (f.u == NULL) {
                    ret();
                }
                break;
            case 1:
                res.push_back(f.u->val);
                break;
            case 2:
                call(f.u->left);
                break;
            case 3:
                call(f.u->right);
                break;
            case 4:
                ret();
                break;
            default:
                break;
            }
        }
        return res;
    }
};