#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        unordered_set<int> vis;
        int n = parents.size();
        vector<int> ans(n, 1);
        vector<int> g[n];

        auto it = find(nums.begin(), nums.end(), 1);
        if (it == nums.end()) {
            return ans;
        }

        for (int i = 1; i < n; ++i) {
            int p = parents[i];
            g[p].push_back(i);
        }

        function<void(int)> dfs = [&] (int u) {
            vis.insert(nums[u]);
            for (int v : g[u]) {
                if (vis.find(nums[v]) == vis.end()) {
                    dfs(v);
                }
            }
        };

        int cur = it - nums.begin(), mex = 1;
        while (cur != -1) {
            dfs(cur);
            while (vis.find(mex) != vis.end()) {
                mex++;
            }
            ans[cur] = mex;
            cur = parents[cur];
        }
        return ans;
    }
};