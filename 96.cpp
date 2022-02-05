class Solution {
public:
    int numTrees(int n) {
        long long dp[25][25] = {0};
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j)
                dp[i][j] = 1;
        }
        for(int s = 1; s <= n; ++s){
            for(int l = 1; l + s - 1 <= n; ++l){
                int r = l + s - 1;
                for(int rt = l; rt <= r; ++rt){
                    dp[l][r] += (dp[l][rt - 1] * dp[rt + 1][r]);
                }
            }
        }
        return dp[1][n];
    }
};

