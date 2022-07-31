class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int ans = 0, num = 1, n = grades.size();
        while (true) {
            if (n < num) {
                break;
            }
            n -= num;
            num += 1;
            ans += 1;
        }
        return ans;
    }
};