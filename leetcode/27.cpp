#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(), cnt = 0, i = 0, j = 0;
        while (j < n) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
                cnt++;
            } 
            j++;
        }
        return cnt;
    }
};