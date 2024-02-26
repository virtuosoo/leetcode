#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hashCode(vector<int>& cnt) {
        int base = 233, mod = 1e9 + 7;
        int res = 0;
        for (int a : cnt) {
            res = ((long long) res * base + a) % mod;
        }
        return res;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > ans;
        map<int, vector<string> > mp;
        for (string &s : strs) {
            vector<int> cnt(26);
            for (char c : s) {
                cnt[c - 'a']++;
            }
            int code = hashCode(cnt);
            mp[code].emplace_back(s);
        }

        for (auto it : mp) {
            ans.emplace_back(it.second);
        }
        return ans;
    }
};