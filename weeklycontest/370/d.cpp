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


class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        vector<int> a = nums;
        int n = a.size();
        for (int i = 0; i < n; ++i) {
            a[i] -= i;
        }

        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());

        BIT bit(a.size());

        for (int i = 0; i < n; ++i) {
            int j = lower_bound(a.begin(), a.end(), nums[i] - i) - a.begin() + 1;
            long long val = max(bit.query(j), 0ll) + nums[i];
            bit.update(j, val);
        }

        return bit.query(a.size());
    }
};