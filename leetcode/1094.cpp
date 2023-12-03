#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> sub(1005);
        for (auto &t : trips) {
            sub[t[1]] += t[0];
            sub[t[2]] -= t[0];
        }
        int s = 0;
        for (int i = 0; i <= 1000; ++i) {
            s += sub[i];
            if (s > capacity) return false;
        }
        return true;
    }
};