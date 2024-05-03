#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return qsort(nums, 0, n - 1, n - k);
    }

    int qsort(vector<int> &nums, int first, int last, int index) {
        int randIdx = rand() % (last - first + 1) + first;
        swap(nums[first], nums[randIdx]);
        int l = first, r = last;
        int tmp = nums[l];
        while (l < r) {
            //这里的两个while，至少要有一个取等号，不然会无限循环
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
        if (l == index) {
            return nums[l];
        }
        if (l > index) {
            return qsort(nums, first, l - 1, index);
        } else {
            return qsort(nums, l + 1, last, index);
        }
    }
};