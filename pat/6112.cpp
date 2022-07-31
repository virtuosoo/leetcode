class Solution {
public:
    int fillCups(vector<int>& amount) {
        int ans = 0;
        while (true) {
            sort(amount.begin(), amount.end());

            if (amount[2] == amount[1] && amount[2] == 0) {
                break;
            }

            if (amount[2] >= 1) {
                amount[2] -= 1;
            }

            if (amount[1] >= 1) {
                amount[1] -= 1;
            }

            ans += 1;
        }
        return ans;
    }
};