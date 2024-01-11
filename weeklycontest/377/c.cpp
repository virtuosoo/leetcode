#include <bits/stdc++.h>
using namespace std;

const long long INF = LONG_LONG_MAX / 2;
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long> > dis(26, vector<long long>(26, INF));
        for (int i = 0; i < 26; ++i) {
            dis[i][i] = 0;
        }
        for (int i = 0; i < original.size(); ++i) {
            int u = original[i] - 'a', v = changed[i] - 'a';
            dis[u][v] = min(dis[u][v], (long long)cost[i]);
        }

        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }

        long long res = 0;
        for (int i = 0; i < source.length(); ++i) {
            int u = source[i] - 'a', v = target[i] - 'a';
            if (dis[u][v] == INF) {
                res = -1;
                break;
            }
            res += dis[u][v];
        }
        return res;
    }
};