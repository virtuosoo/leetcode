#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> g[numCourses];
        vector<int> inDegree(numCourses);
        for (vector<int> &pre : prerequisites) {
            g[pre[0]].push_back(pre[1]);
            inDegree[pre[1]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        int canFinishCnt = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            canFinishCnt++;
            for (int v : g[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        return canFinishCnt == numCourses;
    }
};