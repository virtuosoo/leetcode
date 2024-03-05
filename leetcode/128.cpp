#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (int num : nums) {
            num_set.insert(num);
        }

        int ans = 0;
        for (int num : num_set) {
            int tmp = 0, cur = num;
            if (num_set.find(num - 1) == num_set.end()) {
                while (num_set.find(cur) != num_set.end()) {
                    cur++;
                    tmp++;
                }
            }
            ans = max(ans, tmp);
        }
        return ans;
    }
};