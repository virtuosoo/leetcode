#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long res = 0;
        for (int x = 0; x <= min(n, limit); ++x) {
            int tn = n - x;
            int l = max(tn - limit, 0), r = min(tn, limit);
            if (l > r) {
                continue;
            }
            //printf("x %d l %d r %d\n", x, l , r);
            res += (r - l + 1);
        }
        return res;
    }
};

int main()

{
    Solution s;
    s.distributeCandies(5, 2);
}