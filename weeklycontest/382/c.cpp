#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long flowerGame(int n, int m) {
        long long n_even = n / 2, n_odd = (n + 1) / 2;
        long long m_even = m / 2, m_odd = (m + 1) / 2;
        return n_even * m_odd + n_odd * m_even;
    }
};