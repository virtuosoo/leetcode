#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<int> v_01, v_10;
        vector<string> res;
        int b = 0;
        for (int i = 0; i < n; ++i) {
            if (groups[i] == b) {
                v_01.push_back(i);
                b ^= 1;
            }
        }
        b = 1;
        for (int i = 0; i < n; ++i) {
            if (groups[i] == b) {
                v_10.push_back(i);
                b ^= 1;
            }
        }

        if (v_01.size() > v_10.size()) {
            for (int idx : v_01) {
                res.push_back(words[idx]);
            }
        } else {
            for (int idx : v_10) {
                res.push_back(words[idx]);
            }
        }
        return res;
    }
};