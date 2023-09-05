#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(string num) {
        int n = num.length();
        int res = n;
        for (int i = n - 1; i >= 0; --i) {
            if (num[i] == '0') {
                res = min(res, n - 1);
                for (int j = i - 1; j >= 0; --j) {
                    if (num[j] == '0' || num[j] == '5') {
                        res = min(res, n - 1 - j  - 1);
                    }
                }
            }
            if (num[i] == '5') {
                for (int j = i - 1; j >= 0; --j) {
                    if (num[j] == '2' || num[j] == '7') {
                        res = min(res, n - 1 - j  - 1);
                    }
                }
            }
        }
        return res;
    }
};