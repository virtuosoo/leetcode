#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        vector<int> leftLess(n), rightLess(n);
        vector<long long> leftSum(n), rightSum(n);
        stack<int> stk;

        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && maxHeights[stk.top()] > maxHeights[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                leftLess[i] = stk.top();
            } else {
                leftLess[i] = -1;
            }
            stk.push(i);
        }

        while (!stk.empty()) {
            stk.pop();
        }
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && maxHeights[stk.top()] > maxHeights[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                rightLess[i] = stk.top();
            } else {
                rightLess[i] = n;
            }
            stk.push(i);
        }

        leftSum[0] = maxHeights[0];
        for (int i = 1; i < n; ++i) {
            if (maxHeights[i] >= maxHeights[i - 1]) {
                leftSum[i] = leftSum[i - 1] + maxHeights[i];
            } else {
                int pre = leftLess[i];
                if (pre == -1) {
                    leftSum[i] = (long long) (i + 1) * maxHeights[i];
                } else {
                    leftSum[i] = (long long) leftSum[pre] + ((long long) i - pre) * maxHeights[i];
                }
            }
        }

        rightSum[n - 1] = maxHeights[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            if (maxHeights[i] >= maxHeights[i + 1]) {
                rightSum[i] = rightSum[i + 1] + maxHeights[i];
            } else {
                int pre = rightLess[i];
                if (pre == n) {
                    rightSum[i] = (long long) (n - i) * maxHeights[i];
                } else {
                    rightSum[i] = (long long) rightSum[pre] + ((long long) pre - i) * maxHeights[i];
                }
            }
        }

        long long res = 0;
        for (int i = 0; i < n; ++i) {
            res = max(res, leftSum[i] + rightSum[i] - maxHeights[i]);
        }
        return res;
    }
};