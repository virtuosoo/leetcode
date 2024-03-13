#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size(), m = n / 2, sum = 0;
        for (int num : nums) sum += num;

        map<int, set<int> *> mp;
        for (int i = 0; i < (1 << m); ++i) { //计算出前半部分有的[tot, cnt] 二元组
            int cnt = 0, tot = 0;
            for (int j = 0; j < m; ++j) {
                if ((i >> j) & 1) {
                    cnt++;
                    tot += nums[j];
                }
            }
            set<int> *st = mp[tot];
            if (st == nullptr) {
                st = new set<int>();
            }
            st->insert(cnt);
            mp[tot] = st;
        }

        // 假设当前搜到[tot, cnt]
        // 需要判断之前的搜索结果中是否存在[x, y]， 使得(tot + x) / (cnt + y) = avg = sum / n
        // 因此枚举cnt + y的指，假设其为k
        for (int i = 0; i < (1 << (n - m)); ++i) {
            int cnt = 0, tot = 0;
            for (int j = 0; j < n - m; ++j) {
                if ((i >> j) & 1) {
                    cnt++;
                    tot += nums[j + m];
                }
            }

            for (int k = max(1, cnt); k <= n - 1; ++k) {
                if (k * sum % n != 0) continue;
                int t = k * sum / n;
                set<int> *s = mp[t - tot];
                if (s != nullptr && s->find(k - cnt) != s->end()) {
                    return true;
                }
            }
        }
        return false;
    }
};