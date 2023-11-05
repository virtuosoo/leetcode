#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        vector<int> a = nums;
        int n = a.size();
        for (int i = 0; i < n; ++i) {
            a[i] -= i;
        }

        vector<long long> dp(n);

        


    }
};