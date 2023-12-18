#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) { // (points[k][1] - points[j][1]) / (points[k][0] - points[j][0])
        int n = points.size();                   // (points[k][1] - points[i][1]) / (points[k][0] - points[i][0])
        if (n < 3) {
            return n;
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int cnt = 2;
                for (int k = j + 1; k < n; ++k) {
                    if ((points[k][1] - points[j][1]) * (points[k][0] - points[i][0])
                        == (points[k][1] - points[i][1]) * (points[k][0] - points[j][0]))
                    cnt++;
                }
                res = max(res, cnt);
            }
        }
        return res;
    }
};