#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;

map<string, int> mp;
int tot;

vector<int> g[N];

void dfs()
{
}

void addword(string word)
{
    if (mp[word] == 0) {
        mp[word] = ++tot;
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        int dotnum = 0;
        char c;
        while (true) {
            c = getchar();
            if (c == ',') {
                dotnum += 1;
                if (dotnum == 3) {
                    break;
                }
            }
        }
        string rm, sm;
        while (true) {
            c = getchar();
            if (c == ',') break;
            rm += c;
        }



    }
}
