#include <bits/stdc++.h>
using namespace std;

//子串的长度是固定的，只有26种情况，用滑动窗口来统计
class Solution {
public:
    bool check(int cnt[26], int k) {
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] != 0 && cnt[i] != k) {
                return false;
            }
        }
        return true;
    }

    int count(const string &s, int k) {
        int n = s.length(), res = 0;
        for(int m = 1; m <= 26; ++m) {
            int cnt[26] = {};
            int len = m * k, right = 0;
            if (len > n) {
                break;
            }
            for (right = 0; right < n; ++right) {
                cnt[s[right] - 'a']++;
                int left = right - len + 1;
                if (left >= 0) {
                    if (check(cnt, k)) {
                        res++;
                    }
                    cnt[s[left] - 'a']--;
                }
            }
        }
        return res;
    }
    int countCompleteSubstrings(string word, int k) {
        int n = word.length();
        int pre = 0, res = 0;
        for (int i = 1; i < n; ++i) {
            if (abs(word[i] - word[i - 1]) > 2) {
                res += count(word.substr(pre, i - pre), k);
                pre = i;
            }
        }
        res += count(word.substr(pre, n - pre), k);
        return res;
    }
};