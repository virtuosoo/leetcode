#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.length(), m = b.length();
        int res = kmp(a, b);
        //printf("%d\n", res);
        if (res == -1) {
            return -1;
        } else {
            return res / n + 1; //向上取整
        }
    }

    int kmp(string s, string pat) {
        int n = s.length(), m = pat.length();
        vector<int> nxt(m);
        int i, j;
        for (int j = 0, i = 1; i < m; ++i) {
            while (j != 0 && pat[i] != pat[j]) {
                j = nxt[j - 1];
            }
            if (pat[i] == pat[j]) {
                j ++;
            }
            nxt[i] = j;
        }

        i = 0, j = 0;
        while (true) {
            if (i - j > n) { //想一想， i=n, j = 0时，合理吗？
                break;
            }
            while (j != 0 && s[i % n] != pat[j]) {
                j = nxt[j - 1];
            }
            if (s[i % n] == pat[j]) {
                j++;
            }
            if (j == m) {
                return i;
            }
            i++;
        }
        return -1;
    }
};