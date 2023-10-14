#include <vector>
#include <queue>
using namespace std;

int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
public:
    vector<vector<int> > highestPeak(vector<vector<int> >& isWater) {
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<int> > res(n, vector<int>(m, -1));
        queue<pair<int, int> > q;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(isWater[i][j]){
                    q.push(pair<int, int>(i, j));
                    res[i][j] = 0;
                }
            }
        }

        while (!q.empty()){
            pair<int, int> a = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i){
                int x = a.first + dirs[i][0], y = a.second + dirs[i][1];
                if (0 <= x && x < n && 0 <= y && y < m && res[x][y] == -1){
                    res[x][y] = res[a.first][a.second] + 1;
                    q.push(pair<int, int>(x, y));
                }
            }
        }
        return res;
    }
};