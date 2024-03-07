#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans;
        int n = nums1.size(), m = nums2.size();
        priority_queue<tuple<int, int, int> > q;
        for (int i = 0; i < min(m, k); ++i) {
            q.push({-nums1[0] - nums2[i], 0, i});
        }

        while (!q.empty() && ans.size() < k) {
            auto t = q.top();
            int sum = get<0>(t), i = get<1>(t), j = get<2>(t);
            q.pop();
            ans.push_back(-sum);
            if (i + 1 < n) {
                q.push({-nums1[i + 1] - nums2[j], i + 1, j});
            }
        }
        return ans;
    }

    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        vector<int> a = mat[0];
        for (int i = 1; i < n; ++i) {
            a = kSmallestPairs(a, mat[i], k);
        }
        return a.back();
    }
};