#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n = nums.size();
        vector<long long> res;
        unordered_map<int, long long> cnt;
        multiset<long long> st;
        for (int i = 0; i < n; ++i) {
            int id = nums[i];
            long long cur = cnt[id];
            auto it = st.find(cur);
            if (it != st.end()) {
                st.erase(it);
            }
            cur += freq[i];
            cnt[id] = cur;
            st.insert(cur);
            res.push_back(*st.rbegin());
        }
        return res;
    }
};