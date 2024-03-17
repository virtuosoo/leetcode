#include <bits/stdc++.h>
using namespace std;

//马拉车,manacher算法
class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, end = -1;
        string t = "#";
        for (char c : s) {
            t += c;
            t += '#';
        }

        int n = t.length(), j = -1, right = -1, max_arm = -1;
        vector<int> arms(n);
        for (int i = 0; i < n; ++i) {
            int k = (i > right) ? 1 : min(right - i, arms[2 * j - i]);
            while (i - k >= 0 && i + k < n && t[i - k] == t[i + k]) {
                k++;
            }
            k--;
            arms[i] = k;
            if (i + k > right) {
                j = i;
                right = i + k;
            }
            if (k > max_arm) {
                max_arm = k;
                start = i - k;
                end = i + k;
            }
        }

        string ans;
        for (int i = start; i <= end; ++i) {
            if (t[i] != '#') ans += t[i];
        }
        return ans;
    }
};