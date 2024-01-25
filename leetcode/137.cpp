#include <bits/stdc++.h>
using namespace std;

//设唯一的数为x，某bit位为1的数的个数为a，则x对应为1的位，a % 3 == 1,其他位a % 3 == 0
//设一个数组cnt[32]，其取值为0, 1, 2循环，可以优化成用两个数low, high来表示。
//low和high上的每一个对应的位组合起来表示一个0到3的数。
//当low和high某位都为1时，将其都重置为0
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int low = 0, high = 0;
        for (int a : nums) {
            int carry = low & a;
            low ^= a;
            high |= carry;
            int reset = low & high;
            low ^= reset;
            high ^= reset;
        }
        return low;
    }
};