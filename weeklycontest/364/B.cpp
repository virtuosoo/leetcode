#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        long long res = 0;
        for (int i = 0; i < n; ++i) {
            long long tmp = 0;
            int cur = maxHeights[i];
            tmp += cur;
            for (int j = i - 1; j >= 0; --j) {
                cur = min(cur, maxHeights[j]);
                tmp += cur;
            }
            cur = maxHeights[i];
            for (int j = i + 1; j < n; ++j) {
                cur = min(cur, maxHeights[j]);
                tmp += cur;
            }
            res = max(res, tmp);
        }
        return res;
    }
};