class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int res = 0;
        for (int i = 0; i <= 30; ++i) {
            int cnt = 0;
            for (int &a : nums) {
                if ((a & (1 << i))  != 0) {
                    cnt ++;
                    printf("%d %d\n", i, a);
                }
            }
            if (cnt >= k) {
                res += (1 << i);
            }
        }
        return res;
    }
};