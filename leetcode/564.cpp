#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
    long long myPow(int a, int b) {
        long long res = 1ll;
        while (b) {
            res = res * a;
            b--;
        }
        return res;
    }
    string nearestPalindromic(string s) {
        int n = s.length();
        vector<ll> candi;
        candi.push_back(myPow(10, n) + 1);
        candi.push_back(myPow(10, n - 1) - 1);

        ll prefix = strtoll(s.substr(0, (n + 1) / 2).c_str(), NULL, 10);
        ll num = strtoll(s.c_str(), NULL, 0);
        bool isEven = n % 2 == 0;
        for (int a : {prefix - 1, prefix, prefix + 1}) {
            candi.push_back(getNum(a, isEven));
        }

        sort(candi.begin(), candi.end());

        long long ans = -1, mi = 1e18;
        for (ll a : candi) {
            if (a == num) continue;

            if (abs(a - num) < mi) {
                ans = a;
                mi = abs(a - num);
            } 
        }
        return to_string(ans);
    }

    long long getNum(long long pre, bool isEven) {
        if (pre == myPow(10, 9) && isEven) {
            return -1;
        }
        long long res = pre, x;
        x = isEven ? pre : pre / 10;
        for(; x ; x /= 10) {
            res = res * 10 + x % 10;
        }
        return res;
    }
};