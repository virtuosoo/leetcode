#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    constexpr static int LOGN = 36;
    vector<vector<int> > cyc;
    vector<vector<long long> > w;
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        int n = receiver.size();
        cyc = vector<vector<int> > (n, vector<int>(LOGN, -1));
        w = vector<vector<long long> > (n, vector<long long>(LOGN, 0));

        for (int i = 0; i < n; ++i) {
            cyc[i][0] = receiver[i];
            w[i][0] = i;
        }

        for (int j = 1; j < LOGN; ++j) {
            for (int i = 0; i < n; ++i) {
                if (cyc[i][j - 1] != -1) {
                    int mid = cyc[i][j - 1];
                    cyc[i][j] = cyc[mid][j - 1];
                    w[i][j] = w[i][j - 1] + w[mid][j - 1];
                }
            }
        }
        long long res = 0;
        for (int i = 0; i < n; ++i) {
            long long tmp = 0;
            for (int j = LOGN - 1; j >= 0; --j) {
                if ((k >> j) & 1) {
                    if (cyc[i])
                } 
            }
        }
    }
};