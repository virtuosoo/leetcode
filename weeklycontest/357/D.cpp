#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        sort(items.begin(), items.end(), [](const auto &a, const auto &b) {
            return a[0] > b[0];
        });

        int n = items.size();
        set<int> vis;
        stack<int> duplicate;
        long long ans = 0, profit = 0;
        for (int i = 0; i < n; ++i) {
            if (i < k) {
                if (!vis.insert(items[i][1]).second) {
                    duplicate.push(items[i][0]);
                }
                profit += items[i][0];
                long long c = vis.size();
                ans = max(ans, profit + c * c);
            } else {
                if (!duplicate.empty()) {
                    if (vis.insert(items[i][1]).second) {
                        profit -= duplicate.top();
                        profit += items[i][0];
                        duplicate.pop();
                        long long c = vis.size();
                        long long cur = profit + c * c;
                        ans = max(ans, cur);
                    }
                }
            }
        }
        return ans;
    }
};