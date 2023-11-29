#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int> > ps;
        for (int i = 0; i < n; ++i) {
            ps.emplace_back(nums[i], i);
        }      
        sort(ps.begin(), ps.end());

        vector<vector<pair<int, int>>> slices;
        slices.push_back(vector<pair<int, int>>());
        int idx = 0;
        for (int i = 0; i < n; ++i) {
            if ( i != 0 && ps[i].first - ps[i - 1].first > limit) {
                slices.push_back(vector<pair<int, int>>());
                ++idx;
            } 
            slices[idx].push_back(ps[i]);
        }

        vector<int> res(n);
        for (auto &s : slices) {
            vector<int> pos;
            for (int i = 0; i < s.size(); ++i) {
                pos.push_back(s[i].second);
            }
            sort(pos.begin(), pos.end());
            for (int i = 0; i < pos.size(); ++i) {
                res[pos[i]] = s[i].first;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums{1,5,3,9,8};
    int limit = 3;
    auto res = Solution().lexicographicallySmallestArray(nums, limit);
    for (auto a : res) {
        printf("%d ", a);
    }
}