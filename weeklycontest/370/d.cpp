#include <bits/stdc++.h>
using namespace std;

class BIT {
    vector<long long> tree;
    int n;
public:
    BIT(int n) {
        tree.resize(n);
        this->n = n;
    }

    void update(int pos, int val) {
        for (int i = pos; i < n; i += lowbit(i)) {
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

        vector<long long> dp(n);

        


    }
};