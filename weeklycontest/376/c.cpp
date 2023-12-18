#include <bits/stdc++.h>
using namespace std;

vector<int> pal;
auto init = []() {
    for (int base = 1; base <= 100000 - 1; ++base) {
        int x = base;
        for (int t = x / 10; t ; t /= 10) { //奇数长度的回文数
            x = 10 * x + t % 10;
        }
        pal.push_back(x);

        if (base <= 10000 - 1) {
            x = base;
            for (int t = x; t; t /= 10) { //偶数长度的回文串
                x = 10 * x + t % 10;
            }
            pal.push_back(x);
        }
    }
    pal.push_back(1000000001);
    sort(pal.begin(), pal.end());
    return 0;
}();

class Solution {
public:
    long long minimumCost(vector<int>& nums) {
        int n = nums.size();
        auto cost = [&](int x) {
            long long res = 0;
            for (int a : nums) {
                res += abs(a - x);
            }
            return res;
        };

        sort(nums.begin(), nums.end());
        int i = lower_bound(pal.begin(), pal.end(), nums[(n - 1) / 2]) - pal.begin();
        if (pal[i] == 1) {
            return cost(1);
        } else {
            return min(cost(pal[i]), cost(pal[i - 1]));
        }
    }
};

int main()
{
    // for (int i = 0; i <= 100; ++i) {
    //     printf("%8d ", pal[i]);
    // }
}