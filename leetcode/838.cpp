#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        string ans(n, '.');
        vector<int> force(n), time(n, -1);  //force记录每个块的受力     
        queue<int> q;
        
        for (int i = 0; i < n; ++i) {
            if (dominoes[i] != '.') {
                force[i] = dominoes[i] == 'L' ? -1 : 1;
                time[i] = 0;
                q.push(i);
            }
        }

        while (!q.empty()) {
            int i = q.front();
            q.pop();
            if (force[i] == -1) ans[i] = 'L';
            else if (force[i] == 1) ans[i] = 'R';

            if (force[i] == 0) continue;

            int ni = i + force[i];
            if (ni >= 0 && ni < n) {
                if (time[ni] == -1) {
                    force[ni] += force[i];
                    q.push(ni);
                    time[ni] = time[i] + 1;
                } else if (time[ni] == time[i] + 1) {
                    force[ni] += force[i];
                }
            }
        }
        return ans;
    }
};