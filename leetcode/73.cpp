#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> rowZero(n), colZero(m);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    rowZero[i] = 1;
                    colZero[j] = 1;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (rowZero[i] == 1) {
                for (int j = 0; j < m; ++j) matrix[i][j] = 0;
            }
        }

        for (int j = 0; j < m; ++j) {
            if (colZero[j] == 1) {
                for (int i = 0; i < n; ++i) matrix[i][j] = 0;
            }
        }
    }
};