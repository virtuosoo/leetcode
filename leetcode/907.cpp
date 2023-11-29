#include <bits/stdc++.h>
using namespace std;

//对于每一个数，计算它属于区间最右侧的最小值的次数
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> stk;

        for (int i = 0; i < n; ++i) { //找i左边第一个小于arr[i]的位置
            while (!stk.empty() && arr[i] <= arr[stk.top()]) {
                stk.pop();
            }
            if (!stk.empty()) {
                left[i] = stk.top();
            } else {
                left[i] = -1;
            }
            stk.push(i);
        }

        while (!stk.empty()) stk.pop();
        for (int i = n - 1; i >= 0; --i) { //找i右边第一个小于*或等于*arr[i]的位置
            while (!stk.empty() && arr[i] < arr[stk.top()]) {
                stk.pop();
            }
            if (!stk.empty()) {
                right[i] = stk.top();
            } else {
                right[i] = n;
            }
            stk.push(i);
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            //printf("%d %d %d,%d\n", i, left[i], right[i], (i - left[i]) * (right[i] - i));
            int tmp = (1ll * arr[i] * ((i - left[i]) * (right[i] - i) % MOD)) % MOD;
            res = (res + tmp) % MOD;
        }
        return res;
    }
};