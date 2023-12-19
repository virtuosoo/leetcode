#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int> > colPre(m + 1, vector<int>(n + 1, 0)); //colPre[j][i] 表示第j列，到第i行处的列前缀和
                                                                    //下标都改为从1开始
        for (int j = 1; j <= m; ++j) {
            for (int i = 1; i <= n; ++i) {
                colPre[j][i] = colPre[j][i - 1] + matrix[i - 1][j - 1];
            }
        }
        vector<int> res;
        int ans = INT_MIN;
        for (int i1 = 1; i1 <= n; ++i1) {
            for (int i2 = i1; i2 <= n; ++i2) {
                int preMin = 0, idx = 0, sum = 0;  //preMin表示前缀和的最小值，idx表示最小值在哪个列下标取到
                for (int j = 1; j <= m; ++j) {
                    sum += colPre[j][i2] - colPre[j][i1 - 1];
                    if (ans < sum - preMin) {
                        ans = sum - preMin;
                        res = {i1 - 1, idx, i2 - 1, j - 1};
                    }
                    if (sum < preMin) {
                        preMin = sum;
                        idx = j;
                    }
                }
            }
        }
        return res;
    }
};