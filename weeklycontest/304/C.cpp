class Solution {
public:

    void bfs(int src, vector<int> &dis, int n, vector<int> *g) {
        vector<bool> vis(n);

        dis[src] = 0;
        queue<int> q;
        q.push(src);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            vis[u] = true;

            for (int v : g[u]) {
                if (!vis[v]) {
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        const int nn = n;
        vector<int> g[nn];
        for (int i = 0; i < n; ++i) {
            if (edges[i] != -1)
                g[i].push_back(edges[i]);
        }

        vector<int> dis1(n), dis2(n);
        fill(dis1.begin(), dis1.end(), INT_MAX);
        fill(dis2.begin(), dis2.end(), INT_MAX);

        bfs(node1, dis1, n, g);
        bfs(node2, dis2, n, g);

        int d = INT_MAX, ans = -1;
        for (int i = 0; i < n; ++i) {
            if (dis1[i] != INT_MAX && dis2[i] != INT_MAX) {
                if (max(dis1[i], dis2[i]) < d) {
                    d = max(dis1[i], dis2[i]);
                    ans = i;
                }
            }
        }
        return ans;
    }
};