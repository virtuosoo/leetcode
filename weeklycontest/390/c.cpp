#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<long long> mx(4 * N);

class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        fill(mx.begin(), mx.end(), 0);
        int n = nums.size();
        vector<long long> ans(n);
        for (int i = 0; i < n; ++i) {
            update(1, 1, 100000, nums[i], freq[i]);
            ans[i] = mx[1];
        }
        return ans;
    }

    void update(int rt, int l, int r, int idx, int val) {
        if (l == r) {
            mx[rt] += val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid) {
            update(rt << 1, l, mid, idx, val);
        } else {
            update(rt << 1 | 1, mid + 1, r, idx, val);
        }
        mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]);
    }
};