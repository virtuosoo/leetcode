#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canTransform(string start, string target) {
        int n = start.length();
        vector<int> pos1, pos2;       //记录L和R的所有位置
        for (int i = 0; i < n; ++i) { 
            if (start[i] != 'X') {
                pos1.push_back(i);
            }

            if (target[i] != 'X') {
                pos2.push_back(i);
            }
        }

        if (pos1.size() != pos2.size()) {
            return false;
        }

        for (int i = 0; i < pos1.size(); ++i) {
            if (start[pos1[i]] != target[pos2[i]]) { //对应的字母不一样
                return false;
            }
            if (start[pos1[i]] == 'L') { //start中对应的L一定在更右边
                if (pos1[i] < pos2[i]) {
                    return false;
                }
            } else {
                if (pos1[i] > pos2[i]) {
                    return false;
                }
            }
        }
        return true;
    }   
};