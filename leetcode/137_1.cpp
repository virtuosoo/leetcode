class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for (int x : nums) {
            int tmp_a = a;
            a = (a ^ x) & (a | b);
            b = (b ^ x) & (~tmp_a);
        }
        return b;
    }
};