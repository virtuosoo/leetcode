#include <bits/stdc++.h>
using namespace std;

struct Node {
    int i, j;
    int price;

    Node(int _i, int _j, int _price) {
        i = _i;
        j = _j;
        price = _price;
    }
    bool operator< (const Node &b) const {
        return this->price > b.price;
    }
};

class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        long long res = 0;

        priority_queue<Node> q;
        int m = values.size();
        int n = values[0].size();
        for (int i = 0; i < m; ++i) {
            q.push(Node(i, n - 1, values[i][n - 1]));
        }

        int day = 1;
        while (!q.empty()) {
            Node nd = q.top();
            q.pop();
            res += 1ll * day * nd.price;
            if (nd.j != 0) {
                q.push(Node(nd.i, nd.j - 1, values[nd.i][nd.j - 1]));
            }
            ++day;
        }
        return res;
    }
};