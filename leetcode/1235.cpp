#include <bits/stdc++.h>
using namespace std;


class BIT {
    vector<long long> tree;
    int n;
public:
    BIT(int n) {
        tree = vector<long long> (n + 1, LLONG_MIN);
        this->n = n;
    }

    void update(int pos, long long val) {
        for (int i = pos; i <= n; i += lowbit(i)) {
            tree[i] = max(tree[i], val);
        }
    }

    long long query(int pos) {
        long long res = LLONG_MIN;
        for (int i = pos; i >= 1; i -= lowbit(i)) {
            res = max(res, tree[i]);
        }
        return res;
    }

    int lowbit(int x) {return x & (-x);}
};

// 树状数组维护dp
// bit.query(t)表示在[1, t]的时间内能取得的最大profit
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<int> tmp;
        for (int i = 0; i < n; ++i) {
            tmp.push_back(startTime[i]);
            tmp.push_back(endTime[i]);
        }
        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
        for (int i = 0; i < n; ++i) {
            startTime[i] = lower_bound(tmp.begin(), tmp.end(), startTime[i]) - tmp.begin() + 1;
            endTime[i] = lower_bound(tmp.begin(), tmp.end(), endTime[i]) - tmp.begin() + 1;
        }
        BIT bit = BIT(tmp.size() + 1);
        vector<int> id(n);
        int ans = 0;
        for (int i = 0; i < n; ++i) id[i] = i;
        sort(id.begin(), id.end(), [&](int i, int j) {
            return endTime[i] < endTime[j];
        });

        for (int i = 0; i < n; ++i) {
            int u = id[i];
            int val = profit[u] + bit.query(startTime[u]);
            bit.update(endTime[u], val);
            ans = max(ans, val);
        }
        return ans;

    }
};