#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int n = batteryPercentages.size();
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (batteryPercentages[i] - cnt > 0) {
                cnt++;
            }
        }
        return cnt;
    }
};