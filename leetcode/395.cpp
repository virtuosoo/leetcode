#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // O(n * 26 * 26), 常数有点大
    int longestSubstring(string s, int k) {
        int n = s.length();
        int res = 0;

        auto check = [&](int cnt[26], int k) {
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] && cnt[i] < k) {
                    return false;
                }
            }
            return true;
        };

        for (int m = 1; m <= 26; ++m) {
            set<int> st{};
            int cnt[26] = {};
            int left = 0, right = 0;
            for (right = 0; right < n; ++right) {
                st.insert(s[right] - 'a');
                cnt[s[right] - 'a']++;
                while (st.size() > m) {
                    cnt[s[left] - 'a']--;
                    if (cnt[s[left] - 'a'] == 0) {
                        st.erase(s[left] - 'a');
                    }
                    left++;
                }
                if (st.size() == m && right - left + 1 >= m * k && check(cnt, k)) {
                    res = max(res, right - left + 1);
                }
            }
        }
        return res;
    }


    //优化一下
    int longestSubstring1(string s, int k) {
        int n = s.length();
        int res = 0;

        for (int m = 1; m <= 26; ++m) {
            int cnt[26] = {};
            int tot = 0, ok = 0; //tot表示区间内字符的种类数, ok表示区间内个数 >=k 的字符数
            for(int j = 0, i = 0; i < n; ++i) {
                int c = s[i] - 'a';
                cnt[c]++;

                if (cnt[c] == 1) tot++;
                if (cnt[c] == k) ok++;

                while (tot > m) {
                    c = s[j] - 'a';
                    cnt[c] --;
                    if (cnt[c] == 0) tot--;
                    if (cnt[c] == k - 1) ok--;
                    j++;
                }

                if (tot == m && ok == m) res = max(res, i - j + 1);
            }
        }
        return res;
    }
};