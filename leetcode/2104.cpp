#include <vector>
using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        vector<int> Lmin(n, -1), Rmin(n, n), Lmax(n, -1), Rmax(n, n);
        vector<int> upstack, downstcak;

        for(int i = 0; i < n; ++i){
            while(upstack.size() != 0 && nums[upstack.back()] > nums[i]){
                Rmin[upstack.back()] = i;
                upstack.pop_back();
            }
            upstack.push_back(i);

            while(downstcak.size() != 0 && nums[downstcak.back()] <= nums[i]){
                Rmax[downstcak.back()] = i;
                downstcak.pop_back();
            }
            downstcak.push_back(i);
        }

        upstack.clear();
        downstcak.clear();

        for(int i = n - 1; i >= 0; --i){
            while(upstack.size() != 0 && nums[upstack.back()] >= nums[i]){
                Lmin[upstack.back()] = i;
                upstack.pop_back();
            }
            upstack.push_back(i);

            while(downstcak.size() != 0 && nums[downstcak.back()] < nums[i]){
                Lmax[downstcak.back()] = i;
                downstcak.pop_back();
            }
            downstcak.push_back(i);
        }

        for(int i = 0; i < n; ++i){
            ans -= (long long) nums[i] * (i - Lmin[i]) * (Rmin[i] - i);
            ans += (long long) nums[i] * (i - Lmax[i]) * (Rmax[i] - i);
        }
        return ans;
    }
};