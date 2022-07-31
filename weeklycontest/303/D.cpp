class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        vector<int> cnt(70);
        set<int> st;
        for (int &num : nums) {
            st.insert(num);
        }

        for (int num : st) {
            int c = 0;
            while(num) {
                if (num & 1) {
                    c += 1;
                }
                num >>= 1;
            }
            cnt[c]++;
        }

        long long ans = 0ll;
        for (int i = 0; i < 70; ++i) {
            for (int j = 0; j < 70; ++j) {
                if (i + j >= k) {
                    ans += (long long) cnt[i] * cnt[j];
                } 
            }
        }
        return ans;
    }
};