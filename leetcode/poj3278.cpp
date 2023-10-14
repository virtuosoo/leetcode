#include <iostream>
#include <queue>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 100000;
int vis[MAXN + 5];
int ans;

void solve()
{
    memset(vis, 0, sizeof(vis));
    int n, k;
    cin >> n >> k;
    queue<pair<int, int> > q;
    q.push(make_pair(n, 0));

    while (!q.empty()){
        int u = q.front().first, step = q.front().second;
        q.pop();
        vis[u] = 1;
        if (u == k) {
            ans = step;
            break;
        }
        int nxt[] = {u - 1, u + 1, 2 * u};
        for (int i = 0; i < 3; ++i){
            if (nxt[i] >= 0 && nxt[i] <= MAXN && !vis[nxt[i]]) {
                q.push(make_pair(nxt[i], step + 1));
            }
        }
    }
    cout << ans << '\n';
}
int main()
{
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

}