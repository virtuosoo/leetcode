#include <bits/stdc++.h>
using namespace std;

const int N = 10010;
int f[N], area[N], memberNum[N], setNum[N], minId[N];
bool vis[N];
struct outInfo{
    int id, memberNum;
    double avgSet, avgArea;

    outInfo(int id, int Num, double set, double area):
        id(id), memberNum(Num), avgSet(set), avgArea(area)
    {}
    bool operator< (const outInfo &rhs) {
        if (abs(avgArea - rhs.avgArea) < 1e-6) {
            return id < rhs.id;
        }
        return avgArea > rhs.avgArea;
    }
};

int find(int x)
{
    if (x == f[x]) return x;
    f[x] = find(f[x]);
    return f[x];
}

void join(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx != fy) {
        f[fy] = fx;
        minId[fx] = min(minId[fx], minId[fy]);
    }    
}

int main()
{
    for(int i = 0; i <= 10000; ++i) {
        f[i] = i;
        memberNum[i] = 1;
        minId[i] = i;
    }

    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        int id, fa, ma, k, child, M, A;
        scanf("%d%d%d%d", &id, &fa, &ma, &k);
        if (fa != -1) join(id, fa);
        if (ma != -1) join(id, ma);
        vis[id] = vis[fa] = vis[ma] = true;
        for(int j = 1; j <= k; ++j){
            scanf("%d", &child);
            join(id, child);
            vis[child] = true;
        }
        scanf("%d%d", &M, &A);
        setNum[id] += M;
        area[id] += A;
    }

    for (int i = 0; i <= 9999; ++i) {
        if (vis[i]) {
            int fa = find(i);
            if (fa != i){
                setNum[fa] += setNum[i];
                area[fa] += area[i];
                memberNum[fa] += 1;
            }
        }
    }

    vector<outInfo> v;
    for(int i = 0; i <= 9999; ++i) {
        if (vis[i] && i == find(i)) {
            outInfo info(minId[i], memberNum[i], 1.0 * setNum[i] / memberNum[i], 1.0 * area[i] / memberNum[i]);
            v.push_back(info);
        }
    }

    printf("%d\n", v.size());
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); ++i) {
        outInfo info = v[i];
        printf("%04d %d %.3lf %.3lf\n", info.id, info.memberNum, info.avgSet, info.avgArea);
    }
    return 0;
}