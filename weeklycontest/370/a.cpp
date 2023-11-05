#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int j = 0; j < n; ++j) {
            int c = 0;
            for (int i = 0; i < n; ++i) {
                c += grid[i][j];
            }
            if (c == 0) {
                return j;
            }
        }
        return -1;
    }
};