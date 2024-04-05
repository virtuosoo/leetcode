#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        array<int, 3> jobs[n + 1];
        for (int i = 1; i <= n; ++i) {
            jobs[i] = {endTime[i - 1], startTime[i - 1], profit[i - 1]};
        }

        sort(jobs + 1, jobs + 1 + n, [&](auto &a, auto &b) {
            return a[0] < b[0];
        });

        // dp[i]表示只选[1, i]中的工作，可能获得的最大profit
        // 不一定要选第i个工作。
        int dp[n + 1];
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            // 找到最大的j, 满足end[j] <= start[i]
            int l = 0, r = i;
            while (l < r) {
                int mid = (l + r + 1) / 2;
                if (jobs[mid][0] <= jobs[i][1]) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            int j = l;
            dp[i] = max(dp[i - 1], dp[j] + jobs[i][2]);
        }
        return dp[n];
    }
};