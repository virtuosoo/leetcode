#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> > res;
        vector<bool> vis(n);
        function<void(int, vector<int>)> dfs = [&](int pos, vector<int> cur) {
            if (pos == n) {
                res.push_back(cur);
                return;
            }
            for (int i = 0; i < n; ++i) {
                if (!vis[i]) {
                    vis[i] = true;
                    cur.push_back(nums[i]);
                    dfs(pos + 1, cur);
                    cur.pop_back();
                    vis[i] = false;
                }
            }
        };
        vector<int> cur;
        dfs(0, cur);
        return res;
    }
};