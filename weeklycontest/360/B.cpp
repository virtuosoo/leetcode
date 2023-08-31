#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        long long res = 0;

        long long mid = min(target / 2, n);
        res += (1ll + mid) * mid / 2;

        if (mid < n) {
            long long left = n - mid;
            res += (target + (target + left - 1)) * left / 2;
        }

        return res;
    }
};