#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int> > ans;
        int n = nums1.size(), m = nums2.size();
        priority_queue<tuple<int, int, int> > q;
        for (int i = 0; i < min(m, k); ++i) {
            q.push({-nums1[0] - nums2[i], 0, i});
        }

        while (k--) {
            auto t = q.top();
            int i = get<1>(t), j = get<2>(t);
            q.pop();
            ans.push_back({nums1[i], nums2[j]});
            if (i + 1 < n) {
                q.push({-nums1[i + 1] - nums2[j], i + 1, j});
            }
        }
        return ans;
    }
};