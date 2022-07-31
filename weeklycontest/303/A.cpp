class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> num(26);
        for (int i = 0; i < s.length(); ++i) {
            if (num[s[i] - 'a'] == 1) {
                return s[i];
            }
            num[s[i] - 'a']++;
        }
        return 'a';
    }
};