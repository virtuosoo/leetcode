#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        k %= m;
        bool res = true;
        for (int i = 0; i < n; ++i) {
            vector<int> tmp;
            if (i & 1) { //左移
                for (int j = m - k; j < m; ++j) tmp.push_back(mat[i][j]);
                for (int j = 0; j < m - k; ++j) tmp.push_back(mat[i][j]);
                for (int j = 0; j < m; ++j) res &= (tmp[j] == mat[i][j]);
            } else { //右移
                for (int j = k; j < m; ++j) tmp.push_back(mat[i][j]);
                for (int j = 0; j < k; ++j) tmp.push_back(mat[i][j]);
                for (int j = 0; j < m; ++j) res &= (tmp[j] == mat[i][j]);
            }
        }
        return res;
    }
};