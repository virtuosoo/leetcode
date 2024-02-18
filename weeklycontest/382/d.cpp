#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOrAfterOperations(vector<int>& nums, int k) {
        int mask = 0, ans = 0;
        for (int b = 29; b >= 0; --b) {
            mask |= (1 << b);
            int and_res = -1, cnt = 0;
            for (int num : nums) {
                and_res &= (num & mask);
                if (and_res) {
                    cnt++;
                } else {
                    and_res = -1;
                }
            }

            if (cnt > k) {
                mask ^= (1 << b);
                ans |= (1 << b);
            } 
        }
        return ans;
    }
};