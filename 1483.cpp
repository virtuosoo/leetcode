#include <bits/stdc++.h>
using namespace std;

//倍增，求第k个祖先
class TreeAncestor {
public:
    constexpr static int LOGN = 22;
    vector<vector<int> > fa;
    TreeAncestor(int n, vector<int>& parent) {
        fa = vector<vector<int> > (n, vector<int> (LOGN, -1));
        for (int i = 0; i < n; ++i) {
            fa[i][0] = parent[i];
        }

        for (int j = 1; j < LOGN; ++j) {
            for (int i = 0; i < n; ++i) {
                if (fa[i][j - 1] != -1) {
                    fa[i][j] = fa[fa[i][j - 1]][j - 1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int res = node;
        for (int j = LOGN - 1; j >= 0; --j) {
            if ((k >> j) & 1) {
                res = fa[res][j];
                if (res == -1) {
                    break;
                }
            }
        }
        return res;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */