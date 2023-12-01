#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long beautifulSubstrings(string s, int k) {
        int n = s.length();
        k = getK(k * 4);
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        map<pair<int, int>, int> mp;
        mp[{0, 0}] = 1;

        int res = 0, sum = 0;
        for (int i = 1; i <= n; ++i) {
            int c = vowels.count(s[i - 1]) == 1 ? 1 : -1;
            sum += c;
            if (mp.find({i % k, sum}) != mp.end()) {
                res += mp[{i % k, sum}];
            }
            mp[{i % k, sum}]++;
        }
        return res;
    }

    int getK(int n) {
        int res = 1;
        for (int i = 2; i * i <= n; ++i) {
            int cnt = 0;
            while (n % i == 0) {
                n /= i;
                cnt++;
            }
            for (int j = 1; j <= (cnt + 1) / 2; ++j) {
                res *= i;
            }
        }

        if (n > 1) res *= n;
        return res;
    }
};