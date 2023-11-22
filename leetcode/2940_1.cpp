#include <bits/stdc++.h>
using namespace std;


//线段树上的二分查找
class Solution {
public:
    vector<int> mx; //线段树的数组
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        mx.resize(n * 4);
        build(1, 0, n - 1, heights);
        vector<int> res;
        for (auto &q : queries) {
            int i = q[0], j = q[1];
            if (i > j) {
                swap(i, j);
            }
            if (heights[j] > heights[i] || i == j) {
                res.push_back(j);
            } else {
                res.push_back(query(1, 0, n - 1, max(i, j), max(heights[i], heights[j])));
            }
        }
        return res;
    }

    void build(int rt, int l, int r, vector<int> &h) {
        if (l == r) {
            mx[rt] = h[l];
            return;
        }
        int mid = (l + r) / 2;
        build(rt * 2, l, mid, h);
        build(rt * 2 + 1, mid + 1, r, h);
        mx[rt] = max(mx[rt * 2], mx[rt * 2 + 1]);
    }

    int query(int rt, int l, int r, int ql, int val) { //查询下标ql右边的， 值大于val的最左边的下标
        if (mx[rt] <= val) {
            return -1;
        }

        if (l == r) {
            return l;
        }

        int mid = (l + r) / 2;
        int res = -1;
        if (mid > ql) {
            res = query(rt * 2, l, mid, ql, val);
        }
        if (res == -1) {
            res = query(rt * 2 + 1, mid + 1, r, ql, val);
        }
        return res;
    }
};