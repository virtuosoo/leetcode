#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool canChange(string start, string target) {
        int num1 = 0, num2 = 0;
        int n = start.length();
        vector<int> pos1, pos2;
        for (int i = 0; i < n; ++i) {
            if (start[i] != '_') {
                num1 += 1;
                pos1.push_back(i);
            }

            if (target[i] != '_') {
                num2 += 1;
                pos2.push_back(i);
            }
        }

        if (num1 != num2) {
            return false;
        }

        // for (int i = 0; i < num1; ++i) {
        //     printf("%d %d\n", pos1[i], pos2[i]);
        // }


        for (int i = 0; i < num1; ++i) {
            if (start[pos1[i]] != target[pos2[i]]) {
                //printf("1, %d\n", i);
                return false;
            }
            if (start[pos1[i]] == 'L') {
                if (pos1[i] < pos2[i]) {
                    //printf("2, %d\n", i);
                    return false;
                }
            } else {
                if (pos1[i] > pos2[i]) {
                    //printf("3, %d\n", i);
                    return false;
                }
            }
        }
        return true;
    }   
};