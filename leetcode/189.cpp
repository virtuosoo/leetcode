#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        if (k == 0) {
            return;
        }

        int cnt = 0, start = 0;
        while (cnt < n) {
            int cur = start, val = nums[cur];
            do {
                cnt ++;
                int next = (cur + k) % n;
                swap(nums[next], val);
                cur = next;
            } while (cur != start);
            start ++;
        }
        return;
    }
};