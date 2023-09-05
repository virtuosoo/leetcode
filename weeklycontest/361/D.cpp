#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<int> lg2(n + 1);
        for (int i = 2; i <= n; ++) {
            lg2[i] = lg2[i << 1] + 1;
        }
        
        vector<vector<int> fa = vector<vector<int> > (n, vector<int>(18, -1));
    }

    void dfs(int u) {

    }
};