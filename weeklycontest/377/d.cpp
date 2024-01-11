#include <bits/stdc++.h>
using namespace std;

struct Node{
    /* data */
    Node* children[26]{};
    int id = -1;
};

class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        int cnt = 0;
        Node *root = new Node();

        auto insert = [&](string& s) -> int {
            Node *cur = root;
            for (char c : s) {
                if (cur->children[c - 'a'] == nullptr) {
                    cur->children[c - 'a'] = new Node();
                }
                cur = cur->children[c - 'a'];
            }
            if (cur->id == -1) {
                cur->id = cnt++;
            }
            return cur->id;
        };

        int m = cost.size();
        long long inf = LONG_LONG_MAX / 2;
        vector<vector<long long> > dist(m * 2, vector<long long>(m * 2, inf));
        for (int i = 0; i < m * 2; ++i) dist[i][i] = 0;

        for (int i = 0; i < original.size(); ++i) {
            int u = insert(original[i]);
            int v = insert(changed[i]);
            dist[u][v] = min(dist[u][v], (long long) cost[i]);
        }

        for (int k = 0; k < cnt; ++k) {
            for (int i = 0; i < cnt; ++i) {
                if (dist[i][k] == inf) continue;

                for (int j = 0; j < cnt; ++j) {
                    dist[i][j] = min(dist[i][j], dist[i][k] +  dist[k][j]);
                }
            }
        }

        int n = source.length();
        vector<long long> dp(n + 1, inf);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (source[i] == target[i]) {
                dp[i] = dp[i + 1];
            }
            Node *p = root,  *q = root;
            for (int j = i; j < n; ++j) {
                p = p->children[source[j] - 'a'];
                q = q->children[target[j] - 'a'];

                if (p == nullptr || q == nullptr) {
                    break;
                }
                if (p->id >= 0 && q->id >= 0 && dist[p->id][q->id] != inf) {
                    dp[i] = min(dp[i], dp[j + 1] + dist[p->id][q->id]);
                }
            }
        }
        return dp[0] == inf ? -1 : dp[0];
    }
};