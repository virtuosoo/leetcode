#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<bool> not_prime(N);

int getPrime()
{
    vector<int> prime;
    not_prime[1] = true;
    for (int i = 2; i < N; ++i) {
        if (!not_prime[i]) {
            prime.push_back(i);
        }
        for (int p : prime) {
            if (1ll * p * i >= N) break;
            not_prime[p * i] = true;
            if (i % p == 0) break;
        }
    }
    return 1;
}

int init = getPrime();

class Solution {
public:
    vector<int> nodes;
    long long countPaths(int n, vector<vector<int>>& edges) {
        long long res = 0;
        vector<int> g[n + 1], siz(n + 1);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        for (int i = 1; i <= n; ++i) {
            if (!not_prime[i]) {
                long long sum = 0;
                for (int v : g[i]) {
                    if (siz[v] == 0 && not_prime[v]) {
                        nodes.clear();
                        dfs(v, i, g);
                        int s = nodes.size();
                        for (int a : nodes) {
                            siz[a] = s;
                        }
                    }
                    res += 1ll * sum * siz[v];
                    sum += siz[v];
                }
                res += sum;
            }
        }
        return res;
    }

    void dfs(int u, int fa, vector<int> *g) {
        nodes.push_back(u);
        for (int v : g[u]) {
            if (v != fa && not_prime[v]) {
                dfs(v, u, g);
            }
        }
    }
};

// int main()
// {
//     for (int i = 2; i < 100; ++i) {
//         if (!not_prime[i]) {
//             printf("%d ", i);
//         }
//     }
// }