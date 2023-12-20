#include <bits/stdc++.h>
using namespace std;


vector<vector<int> > dire {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > res (n, vector<int>(n, -1));
        int x = 0, y = 0, cur = 1;
        int direIdx = 0;
        while (true) {
            res[x][y] = cur++;
            if (cur > n * n) break;
            int nx, ny;
            for (int i = 0; i < 4; ++i) {
                int nIdx = (direIdx + i) % 4;
                nx = x + dire[nIdx][0], ny = y + dire[nIdx][1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && res[nx][ny] == -1) {
                    direIdx = nIdx;
                    break;
                }
            }
            x = nx, y = ny;
        }
        return res;
    }
};