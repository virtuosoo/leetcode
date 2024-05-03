#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
public:
unordered_map<int, int> indexByValue;
vector<int> nums;
    RandomizedSet() {
        srand(time(NULL));
    }
    
    bool insert(int val) {
        if (indexByValue.count(val) > 0) {
            return false;
        } 
        nums.push_back(val);
        indexByValue[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (indexByValue.count(val) == 0) {
            return false;
        }
        int index = indexByValue[val];
        int last = nums.back();
        nums[index] =  last;
        indexByValue[last] = index;
        nums.pop_back();
        indexByValue.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */