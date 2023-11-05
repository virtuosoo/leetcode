#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> g[n], inDegree(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            inDegree[v] += 1;
        }

        int cnt = 0, res = -1;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                cnt ++;
                res = i;
            }
        }
        if (cnt == 1) {
            return res;
        } else {
            return -1;
        }
    }
};