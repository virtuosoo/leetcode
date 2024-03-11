#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        while (i < j) {
            if (nums[i] == 0) {
                for (; j < n && nums[j] == 0; ++j) {} 
                if (j == n) {
                    break;
                }
                swap(nums[i], nums[j]);
            }
            i++;
            j++;
        }
    }
};