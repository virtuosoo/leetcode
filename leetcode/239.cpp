#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> q;
        for (int i = 0; i < n; ++i) {
            while (!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            if (!q.empty() && i - q.front() >= k) {
                q.pop_front();
            }
            q.push_back(i);
            if (i >= k - 1) {
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
    }
};