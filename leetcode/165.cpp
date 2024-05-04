#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.length(), m = version2.length();
        int i = 0, j = 0;
        while (i < n || j < m) {
            long long x = 0, y = 0;
            while (i < n && version1[i] != '.') {
                x = x * 10 + version1[i] - '0';
                ++i;
            }
            ++i;

            while (j < m && version2[j] != '.') {
                y = y * 10 + version2[j] - '0';
                ++j;
            }
            ++j;
            if (x > y) {
                return 1;
            } else if (x < y) {
                return -1;
            }
        }
        return 0;
    }
};