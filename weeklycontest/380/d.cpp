#include <bits/stdc++.h>
using namespace std;

vector<int> kmp(const string &s, const string &t)
{
    int n = s.length(), m = t.length();
    vector<int> nxt(m), res;
    int j = 0;
    for (int i = 1; i < m; ++i) {
        while (j != 0 && t[i] != t[j]) j = nxt[j - 1];
        if (t[i] == t[j]) j++;
        nxt[i] = j;
    }

    j = 0;
    for (int i = 0; i < n; ++i) {
        while (j != 0 && s[i] != t[j]) j = nxt[j - 1];
        if (s[i] == t[j]) j++;
        if (j == m) {
            res.push_back(i - m + 1);
            j = nxt[j - 1];
        }
    }
    return res;
}

class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> idxA = kmp(s, a), idxB = kmp(s, b), res;
        for (int i : idxA) {
            bool ok = false;
            auto it = lower_bound(idxB.begin(), idxB.end(), i);
            if (it != idxB.end()) {
                if (abs(i - *it) <= k) ok = true;
            }
            if (it != idxB.begin()) {
                --it;
                if (abs(i - *it) <= k) ok = true;
            }
            if (ok) res.push_back(i);
        }
        return res;
    }
};

int main()
{
    auto res = kmp("ababab", "ab");
    for (int a : res) {
        printf("%d ", a);
    }
}