#include <vector>
using namespace  std;  

class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        int n = tires.size();
        vector<long long> best(20);
        int maxDiff = 0;
        fill(best.begin(), best.end(), (long long) (1e9));
        for(int i = 0; i < n; ++i){
            long long tot = tires[i][0], cur = tires[i][0];
            for(int j = 1; j < 20 && cur < changeTime + tires[i][0]; ++j){
                best[j] = min(best[j], tot);
                cur *= tires[i][1];
                tot += cur;
                maxDiff = max(maxDiff, j);
            }
        }

        vector<long long> f(numLaps + 1, (long long) 1e9);
        f[0] = 0;
        for(int i = 1; i <= numLaps; ++i){
            for(int j = i - 1; j >= 0 && i - j <= maxDiff; --j){
                f[i] = min(f[i], f[j] +best[i - j] + changeTime);
            }
        }
        return f[numLaps] - changeTime;
    }
};