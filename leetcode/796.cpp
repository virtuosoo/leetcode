#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int cut = 0, n = arr.size(), mx = -1;

        for (int i = 0; i < n; ++i) {
            mx = max(arr[i], mx);
            if (mx == i) {
                cut++;
            }
        }
        return cut;
    }
};