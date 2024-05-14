#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void maxHeapify(vector<int> &a, int i, int heapSize) {
        int lc = 2 * i + 1, rc = 2 * i + 2, larger = i;
        if (lc < heapSize && a[lc] > a[larger]) {
            larger = lc;
        }
        if (rc < heapSize && a[rc] > a[larger]) {
            larger = rc;
        }
        if (larger != i) {
            swap(a[i], a[larger]);
            maxHeapify(a, larger, heapSize);
        }
    }

    void buildHeap(vector<int> &a, int heapSize) {
        for (int i = heapSize / 2; i >= 0; --i) {
            maxHeapify(a, i, heapSize);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int heapSize = nums.size();
        buildHeap(nums, heapSize);

        //对堆进行k - 1次删除操作。
        for (int i = nums.size() - 1; i >= nums.size() - k + 1; --i) {
            swap(nums[0], nums[i]);
            --heapSize;
            maxHeapify(nums, 0, heapSize);
        }
        return nums[0];
    }
};