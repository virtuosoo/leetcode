#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0, z1 = 0, z2 = 0;
        for (int &a1 : nums1) {
            sum1 += a1;
            if (a1 == 0) {
                z1++;
            }
        }
        for (int &a2 : nums2) {
            sum2 += a2;
            if (a2 == 0) {
                z2++;
            }
        }

        if (sum1 > sum2) {
            swap(sum1, sum2);
            swap(z1, z2);
        }
        
        printf("%d %d %d\n", sum1, z1, sum2);
        if ((z2 == 0 && sum1 + z1 > sum2) || (z1 == 0 && sum1 < sum2 + z2)) {
            return -1;
        }

        return max(sum1 + z1, sum2 + z2);
    }
};