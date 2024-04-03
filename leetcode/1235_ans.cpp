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

        int dp[n + 1];
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            // 注意细节，要找的j是 end[j] <= start[i]
            // 所以这里设置成INT_MAX， 如果设置成0，那么找的是严格小于的。
            int j = upper_bound(jobs + 1, jobs + i + 1, array<int, 3>{jobs[i][1], INT_MAX, 0}) - jobs - 1;
            dp[i] = max(dp[i - 1], dp[j] + jobs[i][2]);
        }
        return dp[n];
    }
};