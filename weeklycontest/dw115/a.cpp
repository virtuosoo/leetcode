#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int> nums;
        vector<int> res;
        int c = 0;
        for (auto &s : words) {
            if (s != "prev") {
                int a = stoi(s);
                printf("%d\n", a);
                nums.push_back(a);
                c = 0;
            } else {
                c += 1;
                int n = nums.size();
                if (n < c) {
                    res.push_back(-1);
                } else {
                    res.push_back(nums[n - c]);
                }
            }
        }
        return res;
    }
};