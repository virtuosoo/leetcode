#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b) {
            return a[0] < b[0];
        });
        vector<vector<int> > res;
        vector<int> cur = intervals[0];
        int i = 1;
        while (i < n) {
            if (intervals[i][0] <= cur[1]) {
                cur[1] = max(cur[1], intervals[i][1]);
                i++;
            } else {
                res.push_back(cur);
                cur = intervals[i];
            }
            i++;
        }
        return res;
    }
};