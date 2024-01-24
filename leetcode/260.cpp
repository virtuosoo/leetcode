#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for (int a : nums) {
            x ^= a;
        }

        int lowbit = x == INT_MIN ? x : x & (-x);
        int x1 = 0, x2 = 0;
        for (int a : nums) {
            if ((a & lowbit) != 0) {
                x1 ^= a;
            } else {
                x2 ^= a;
            }
        }
        return {x1, x2};
    }
};