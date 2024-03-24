#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(int k) {
        int ans = 1e9;
        for (int i = 0; i < k; ++i) {
            ans = min(ans, i + (k + i) / (i + 1) - 1);
        }
        return ans;
    }
};