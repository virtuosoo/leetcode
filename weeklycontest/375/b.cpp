#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int qpow(int a, int b, int m) {
        int res = 1;
        while (b) {
            if (b & 1) res = res * a % m;
            b >>= 1;
            a = a * a % m;
        }
        return res;
    }
    vector<int> getGoodIndices(vector<vector<int>>& v, int target) {
        vector<int> res;
        int n = v.size();
        for (int i = 0; i < n; ++i) {
            int a = v[i][0], b = v[i][1], c = v[i][2], m = v[i][3];
            if (qpow(qpow(a, b, 10), c, m) == target) {
                res.push_back(i);
            }
        }
        return res;
    }
};