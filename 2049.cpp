class Solution {
public:
    long long ans = 0;
    int num = 0;
    int n = 0;
    vector<vector<int> > g;
    int countHighestScoreNodes(vector<int>& parents) {
        n = parents.size();
        g = vector<vector<int> >(n);
        for(int i = 1; i < n; ++i){
            g[parents[i]].emplace_back(i);
        }
        dfs(0);
        return num;
    }
    long long dfs(int u){
        long long siz = 1;
        vector<long long> sonSiz;
        for(int v : g[u]){
            long long tmp = dfs(v);
            siz += tmp;
            sonSiz.push_back(tmp);
        }
        long long sonMul = 1;
        for(long long a : sonSiz){
            sonMul *= a;
        }
        long long curScore = (long long) sonMul * (n - siz);
        if (u == 0){
            curScore = sonMul;
        }
        if (curScore == ans){
            num += 1;
        }
        else if (curScore > ans){
            ans = curScore;
            num = 1;
        }
        return siz;
    }

};