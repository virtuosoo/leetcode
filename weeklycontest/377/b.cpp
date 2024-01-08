#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const int MOD = 1e9 + 7;
        hFences.push_back(1), hFences.push_back(m);
        vFences.push_back(1), vFences.push_back(n);
        unordered_map<int, int> hMap, vMap;
        for (int i = 0; i < hFences.size(); ++i) {
            for (int j = i + 1; j < hFences.size(); ++j) {
                hMap[abs(hFences[j] - hFences[i])] = 1;
            }
        }

        for (int i = 0; i < vFences.size(); ++i) {
            for (int j = i + 1; j < vFences.size(); ++j) {
                vMap[abs(vFences[j] - vFences[i])] = 1;
            }
        }

        int maxE = -1;
        for (auto item : hMap) {
            int e = item.first;
            if (vMap.find(e) != vMap.end()) {
                maxE = max(maxE, e);
            }
        }
        if (maxE == -1) return -1;
        return (1ll * maxE * maxE % MOD);
    }
};