#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bsSearch(int l, int r, vector<int> nums, int target) {
        if (l > r) {
            return -1;
        }
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        if (nums[l] == target) {
            return l;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (nums[mid] > nums[0]) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return max(bsSearch(0, l, nums, target), bsSearch(l + 1, n - 1, nums, target));
    }
};