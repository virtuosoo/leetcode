#include <bits/stdc++.h>
using namespace std;


//有些细节，耐人寻味，比如数学上x < a / 2，和计算机中的不是一样的
//例如x < 5 / 2，数学上x是可以取到2的，但是编程中直接这样写就不行了。
//x > a / 2又如何呢？
class Solution {
public:
    vector<long long> countOfPairs(int n, int x, int y) {
        if (x > y) {
            swap(x, y);
        }

        vector<int> diff(n + 1);
        auto add = [&](int l, int r, int val) {
            if (l > r) {
                return;
            }
            diff[l] += val;
            diff[r + 1] -= val;
        };

        auto update1 = [&](int i, int x, int y) {
            add(y - i, n - i, -1);
            add(x - i + 1, x - i + 1 + n - y, 1);

            int j = (x + y + 1) / 2;
            add(j + 1 - i, y - 1 - i, -1);
            add(x - i + 2, x + y - i - j, 1);
        };

        auto update2 = [&](int i, int x, int y) {
            add(y - i, n - i, -1);
            add(i -x + 1, i - x  + 1 + n - y, 1);

            int j = (y - x + 2 * i + 1) / 2;
            add(j - i + 1, y - 1 - i, -1);
            add(i - x + 2, i - x + y - j, 1);
        };

        for (int i = 1; i <= n; ++i) {
            add(1, i - 1, 1);
            add(1, n - i, 1);
            if (x + 1 >= y) {
                continue;
            }

            if (i <= x) {
                update1(i, x, y);
            } else if (i >= y) {
                update1(n + 1 - i, n + 1 - y, n + 1 - x);
            } else if (i < (x + y) / 2) {
                update2(i, x, y);
            } else if (i > (x + y + 1) / 2) {
                update2(n + 1 - i, n + 1 - y, n + 1 - x);
            }
        }
        vector<long long> ans;
        long long sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += diff[i];
            ans.push_back(sum);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    s.countOfPairs(6, 1, 5);
}