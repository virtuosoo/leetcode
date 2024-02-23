const int MOD = 1e9 + 7, N = 1e5 + 5;
vector<long long> pow_2(N);

int init()
{
    pow_2[0] = 1;
    for (int i = 1; i < N; ++i) {
        pow_2[i] = (pow_2[i - 1] * 2) % MOD;
    }
    return 1;
}
int t = init();

class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            res = (res + nums[i] * pow_2[i]) % MOD;
            res = (res - nums[i] * pow_2[n - i - 1] + MOD) % MOD;
        }
        return res;
    }
};