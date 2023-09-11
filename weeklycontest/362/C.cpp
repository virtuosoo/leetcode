#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int res = 1000;
        int n = 3;
        vector<int> moreOne, zero;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 1) {
                    moreOne.push_back(i * n + j);
                } else if (grid[i][j] == 0) {
                    zero.push_back(i * n + j);
                }
            }
        }

        do {
            int cur = 0, tres = 0;
            for (int a : moreOne) {
                int i = a / n, j = a % n;
                int need = grid[i][j] - 1;
                while (need --) {
                    int x = zero[cur] / n, y = zero[cur] % n;
                    tres += abs(i - x) + abs(j - y);
                    cur++;
                }
            }
            res = min(res, tres);
        }while(next_permutation(zero.begin(), zero.end()));
        return res;
    }
};
