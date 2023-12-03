#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        int cur = 0, res = 0, i = 0;
        while (cur < target) {
            if (i < n) {
                if (coins[i] <= cur + 1) {
                    cur += coins[i];
                } else {
                    while (coins[i] > cur + 1) {
                        cur = cur + cur + 1;
                        res++;
                    }
                    cur += coins[i];
                }
                ++i;
            } else {
                res++;
                cur = cur + cur + 1;
            }
        }
        return res;
    }
};