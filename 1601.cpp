int cntOf1(int x)
{
    int res = 0;
    while (x){
        res += (x & 1);
        x >>= 1;
    }
    return res;
}

class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int m = requests.size();
        vector<int> num(20);
        int ans = 0;
        for(int status = 0; status < (1<<m); ++status){
            fill(num.begin(), num.end(), 0);
            int cnt = cntOf1(status);
            if (cnt < ans){
                continue;
            }
            for(int j = 0; j < m; ++j){
                if ((1<<j) & status){
                    num[requests[j][0]]--;
                    num[requests[j][1]]++;
                }
            }
            bool ok = true;
            for(int k = 0; k < n; ++k){
                ok &= (num[k] == 0);
            }
            if (ok){
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};