
const int N = 1e5 + 5;
class Solution {
public:
    int maxDep;
    int amountOfTime(TreeNode* root, int start) {
        maxDep = -1;
        vector<int> g[N];
        dfs1(root, g, nullptr);
        dfs2(start, -1, g, 0);
        return maxDep;
    }

    void dfs1(TreeNode *cur, vector<int> g[], TreeNode *fa) {
        if (cur == nullptr) {
            return;
        }

        if (fa != nullptr) {
            g[cur->val].push_back(fa->val);
            g[fa->val].push_back(cur->val);
        }
        dfs1(cur->left, g, cur);
        dfs1(cur->right, g, cur);
    }

    void dfs2 (int u, int fa, vector<int> g[], int dep) {
        maxDep = max(maxDep, dep);
        for (int v : g[u]) {
            if (v != fa) {
                dfs2(v, u, g, dep + 1);
            }
        }
    }
};