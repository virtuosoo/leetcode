#include <bits/stdc++.h>
using namespace std;


// 曼哈顿距离转化成切比雪夫距离， 见oiwiki，[距离]章节
class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        multiset<int> xs, ys;
        for (auto &p : points) {
            xs.insert(p[0] + p[1]);
            ys.insert(p[0] - p[1]);
        }

        int res = 1e9;
        for (auto &p : points) {
            int x = p[0] + p[1], y = p[0] - p[1];
            xs.erase(xs.find(x));
            ys.erase(ys.find(y));
            res = min(res, max(*xs.rbegin() - *xs.begin(), *ys.rbegin() - *ys.begin()));

            xs.insert(x);
            ys.insert(y);
        }
        return res;
    }
};