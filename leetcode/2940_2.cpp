#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int nq = queries.size(), nh = heights.size();
        vector<int> res(nq, -1);
        
        vector<vector<pair<int, int> > > list(nh);
        for (int x = 0; x < nq; ++x) {
            auto &q = queries[x];
            int i = q[0], j = q[1];
            if (i > j) {
                swap(i, j);
            }
            if (i == j || heights[j] > heights[i]) {
                res[x] = j;
            } else {
                list[j].emplace_back(heights[i], x); //把询问记录下来
            }
        }

        priority_queue<pair<int, int> ,vector<pair<int, int> > ,greater<> > q;
        for (int x = 0; x < nh; ++x) {
            while (!q.empty() && q.top().first < heights[x]) {
                res[q.top().second] = x;
                q.pop();
            }
            for (auto p : list[x]) {
                q.push(p);
            }
        }
        return res;
    }
};