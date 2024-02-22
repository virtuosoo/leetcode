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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        map<int, int> map_post;
        for(int i = 0; i < n; ++i) {
            map_post[postorder[i]] = i;
        }
        function<TreeNode*(int, int, int, int)> build = [&](int pre_l, int pre_r, int post_l, int post_r) -> TreeNode* {
            if (pre_l > pre_r) {
                return nullptr;
            } 

            if (pre_l == pre_r) {
                return new TreeNode(preorder[pre_l]);
            }

            TreeNode *rt = new TreeNode(preorder[pre_l]);
            int left_len = map_post[preorder[pre_l + 1]] - post_l + 1;
            rt->left = build(pre_l + 1, pre_l + left_len, post_l, post_l + left_len - 1);
            rt->right = build(pre_l + left_len + 1, pre_r, post_l + left_len, post_r);
            return rt;
        };
        return build(0, n - 1, 0, n - 1);
    }
};