class Solution {
public:
    int maximumLength(string s) {
        unordered_map<int, int> mp[26];
        int pre = 0;
        for (int i = 1; i <= s.length(); ++i) {
            if (s[i] != s[i - 1] || i == s.length()) {
                int len = i - pre;
                for (int j = max(1, len - 2); j <= len; ++j) {
                    mp[s[i - 1] - 'a'][j] += (len - j + 1);
                    //printf("%d %d\n", j, len - j + 1);
                }
                pre = i;
            }
        }
        
        int res = -1;
        for (int i = 0; i < 26; ++i) {
            for (auto &e : mp[i]) {
                if (e.second >= 3) {
                    res = max(res, e.first);
                }
            }
        }
        return res;
    }
};