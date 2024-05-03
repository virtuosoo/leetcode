#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        qsort(nums, 0, n - 1);
        return nums[n - k];
    }

    void qsort(vector<int> &nums, int first, int last) {
        if (first >= last) {
            return;
        }
        int l = first, r = last;
        int tmp = nums[l];
        while (l < r) {
            while (l < r && nums[r] >= tmp) {
                --r;
            }
            nums[l] = nums[r];
            while (l < r && nums[l] < tmp) {
                ++l;
            }
            nums[r] = nums[l];
        }
        nums[l] = tmp;
        qsort(nums, first, l - 1);
        qsort(nums, l + 1, last);
    }
};