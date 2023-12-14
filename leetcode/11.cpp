#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int l = 0, r = n - 1, res = 0;
        while (l < r) {
            res = max(res, (r - l) * min(height[l], height[r]));
            if (height[l] <= height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return res;
    }
};