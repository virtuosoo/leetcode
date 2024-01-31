#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<int, int> mp, vis;
        int mx = 0;
        sort(nums.begin(), nums.end());
        for (int a : nums) {
            mp[a]++;
            mx = max(a, mx);
        }
        int res = 0;
        if (mp[1] != 0) {
            res = mp[1] % 2 == 0 ? mp[1] - 1 : mp[1];
        }

        vis[1] = 1;

        for (int i = 0; i < nums.size(); ++i) {
            long long x = nums[i];
            if (vis[x]) continue;
            int t = 1;
            while (mp[x] >= 2 && mp[x * x] >= 1) {
                vis[x] = 1;
                t++;
                x *= x;
                if (x > mx) break;
            }
            res = max(res, 2 * t - 1);
        }
        return res;
    }
};