#include <bits/stdc++.h>
using namespace std;

// kmp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length(), m = needle.length();
        vector<int> nxt(m);

        int j = 0; // j代表之前的最长公共前后缀的长度
        for (int i = 1; i < m; ++i) {
            while (j != 0 && needle[i] != needle[j]) {
                j = nxt[j - 1];
            }
            if (needle[i] == needle[j]) {
                j++;
            }
            nxt[i] = j;
        }

        j = 0; // j代表下一个需要匹配的模式串的位置
        for (int i = 0; i < n; ++i) {
            while (j != 0 && haystack[i] != needle[j]) {
                j = nxt[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == m) {
                return i - m + 1;
            }
        }
        return -1;
    }
};