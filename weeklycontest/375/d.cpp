#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long qpow(long long a, long long b, long long m) {
        int res = 1;
        while (b) {
            if (b & 1) res = res * a % m;
            b >>= 1;
            a = a * a % m;
        }
        return res;
    }

    int numberOfGoodPartitions(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        map<int, int> mp;
        int n = nums.size();
        for (int i = n - 1; i >= 0; --i) {
            if (mp.find(nums[i]) == mp.end()) {
                mp[nums[i]] = i;
            }
        }

        int l = 0, r = 0, cnt = 0;
        while (l < n) {
            r = max(r, mp[nums[l]]);
            if (l == r) cnt++;
            l++;
        }
        return qpow(2, cnt - 1, MOD);
    }
};

int main()
{
    vector<int> nums{}
}