#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> canMakePalindromeQueries(string s, vector<vector<int>>& queries) {
        int n = s.length() / 2;
        string t = s.substr(n);
        reverse(t.begin(), t.end());
        vector<vector<int> > sumS(n + 1, vector<int>(26, 0));
        vector<vector<int> > sumT(n + 1, vector<int>(26, 0));
        vector<int> sumNe(n + 1);

        for (int i = 1; i <= n; ++i) {
            sumS[i] = sumS[i - 1];
            sumS[i][s[i - 1] - 'a']++;
        }

        for (int i = 1; i <= n; ++i) {
            sumT[i] = sumT[i - 1];
            sumT[i][t[i - 1] - 'a']++;
        }

        for (int i = 1; i <= n; ++i) {
            sumNe[i] = sumNe[i - 1] + (s[i - 1] != t[i - 1]);
        }

        auto sub = [](const vector<int> &a, const vector<int> &b) {
            vector<int> res(26);
            for (int i = 0; i < 26; ++i) {
                res[i] = a[i] - b[i];
            }
            return res;
        };

        auto count = [](vector<vector<int>> &sum, int l, int r) ->vector<int> {
            vector<int> res(26);
            for (int i = 0; i < 26; ++i) {
                res[i] = sum[r][i] - sum[l - 1][i];
            }
            return res;
        };


        // l1 <= l2, l1, r1, l2, r2 in [1, n]
        auto check = [&](int l1, int r1, vector<vector<int>> &sum1, 
            int l2, int r2, vector<vector<int>> &sum2) -> bool {
                if (sumNe[l1 - 1] > 0 || sumNe[n] - sumNe[max(r1, r2)] > 0) {
                    return false;
                }

                if (r1 >= r2) {
                    return count(sum1, l1, r1) == count(sum2, l1, r1);
                } else if (l2 > r1) {
                    return count(sum1, l1, r1) == count(sum2, l1, r1) &&
                            count(sum1, l2, r2) == count(sum2, l2, r2) &&
                            sumNe[l1 - 1] == 0 && sumNe[n] - sumNe[r2] == 0 &&
                            sumNe[l2 - 1] - sumNe[r1] == 0;
                } else {
                    vector<int> sub1 = sub(count(sum1, l1, r1), count(sum2, l1, l2 - 1)),
                                sub2 = sub(count(sum2, l2, r2), count(sum1, r1 + 1, r2));
                    for (int i = 0; i < 26; ++i) {
                        if (sub1[i] < 0 || sub2[i] < 0 || sub1[i] != sub2[i]) {
                            return false;
                        }
                    }
                    return true;
                }
        };

        vector<bool> res(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            auto &q = queries[i];
            int l1 = q[0] + 1, r1 = q[1] + 1, l2 = 2 * n - q[3], r2 = 2 * n - q[2];
            res[i] = l1 <= l2 ? check(l1, r1, sumS, l2, r2, sumT) :
                check(l2, r2, sumT, l1, r1, sumS);
        }
        return res;
    }
};

int main()
{
    string s = "abcabc";
    vector<vector<int>> q = {{1,1,3,5}, {0,2,5,5}};
    Solution().canMakePalindromeQueries(s, q);
}