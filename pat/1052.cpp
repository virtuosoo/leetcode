#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

struct node {
    int addr, val, next;

    bool operator< (const node &rhs) {
        return val < rhs.val;
    }
};

node a[N];
int n, headaddr;

map<int, node> mp;
int main()
{
    scanf("%d%d", &n, &headaddr);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d%d", &a[i].addr, &a[i].val, &a[i].next);
        mp[a[i].addr] = a[i];
    }

    //有些节点可能不在链表上，要找出在链表上的节点。
    vector<node> v;
    for (int i = headaddr; i != -1; i = mp[i].next) {
        v.emplace_back(mp[i]);
    }

    if (headaddr == -1 || v.size() == 0) {
        printf("0 -1");
        return 0;
    }
    sort(v.begin(), v.end());

    headaddr = v[0].addr;
    for(int i = 0; i < v.size() - 1; ++i) {
        v[i].next = v[i + 1].addr;
    }
    v[v.size() - 1].next = -1;
    printf("%lu %05d\n", v.size(), headaddr);
    for(int i = 0; i < v.size() - 1; ++i) {
        printf("%05d %d %05d\n", v[i].addr, v[i].val, v[i].next);
    }
    printf("%05d %d -1\n", v.back().addr, v.back().val);
    return 0;
}