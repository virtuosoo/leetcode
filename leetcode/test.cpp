class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int lst = 1, n = nums.size();
        vector<int> ans;

        for(int i = 0; i < n; ++i){
            int g = __gcd(nums[i], lst);
            if (g == 1){
                ans.push_back(nums[i]);
                lst = nums[i];
            }
            else{
                if (lst % nums[i] == 0){
                    continue;
                }
                else{
                    int temp = lst * nums[i] / g;
                    while (ans.size() > 0 && __gcd(temp, ans.back()) != 1){
                        temp = (int)((long long) temp * ans.back()) / __gcd(temp, ans.back());
                        ans.pop_back();
                    }
                    if (i == 87){
                        cout << temp << "!!!!!\n ";
                    }
                    ans.push_back(temp);
                    lst = temp;
                }
            }
            cout << i << ":";
            for(int a : ans){
                cout << a << " ";
            }
            cout << '\n';
        }
        return ans;
    }
};