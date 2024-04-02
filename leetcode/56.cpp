#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int> >res;
        vector<int> cur;
        for (vector<int> &i : intervals) {
            if (cur.empty()) {
                cur = i;
            } else {
                if (i[0] <= cur[1]) {
                    cur[1] = max(i[1], cur[1]);
                } else {
                    res.push_back(cur);
                    cur = i;
                }
            }
        }
        res.push_back(cur);
        return res;
    }
};