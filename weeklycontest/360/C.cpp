#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        int res = 0;
        map<int, int> m;
        vector<int> pow_2(33), cnt(33);
        pow_2[0] = 1;
        m[1] = 0;
        for (int i = 1; i <= 30; ++i) {
            pow_2[i] = pow_2[i - 1] * 2;
            m[pow_2[i]] = i;
        }

        for (int a : nums) {
            cnt[m[a]]++;
        }

        for (int i = 0; i <= 30; ++i) {
            if ((target >> i) & 1) {
                cnt[i] -= 1;
            }
        }

        for (int i = 0; i <= 30; ++i) {
            if (cnt[i] == -1) {
                int j;
                for (j = i + 1; j <= 30; ++j) {
                    if (cnt[j] > 0) {
                        break;
                    }
                }
                if (j == 31) return -1;
                res += (j - i);
                cnt[j] -= 1;
                for (int k = i; k < j; ++k) cnt[k]++;
                cnt[i]++;
            }
            if (cnt[i] >= 2) {
                cnt[i + 1] += cnt[i] / 2;
                cnt[i] -= (cnt[i] / 2 * 2);
            }
        }
        return res;
    }
};