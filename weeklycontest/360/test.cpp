#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        
        int d1 = 0, d2 = 0;
        for (int i = 0; i < moves.size(); ++i) {
            char c = moves[i];
            if (c == 'L') {
                d1 -= 1;
                d2 -= 1;
            } else if (c == '_') {
                d1 -= 1;
                d2 += 1;
            } else {
                d1 += 1;
                d2 += 1;
            }
        }
        return max(abs(d1), abs(d2));
    }
};