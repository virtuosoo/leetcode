#include <bits/stdc++.h>
using namespace std;

int a, b, n;
int mat[1005][1005];

int main()
{
    scanf("%d %d %d", &a, &b, &n);
    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            scanf("%d", &mat[i][j]);
        }
    }

    vector<vector<int> > rowMax, rowMin;
    for (int i = 1; i <= a; ++i) {
        deque<int> minQ, maxQ;
        vector<int> minn, maxn;
        for (int j = 1; j <= b; ++j) {
            if (!minQ.empty() && j - minQ.front() >= n) {
                minQ.pop_front();
            }
            while (!minQ.empty() && mat[i][j] < mat[i][minQ.back()]) {
                minQ.pop_back();
            }
            minQ.push_back(j);

            if (!maxQ.empty() && j - maxQ.front() >= n) {
                maxQ.pop_front();
            }

            while (!maxQ.empty() && mat[i][j] > mat[i][maxQ.back()]) {
                maxQ.pop_back();
            }
            maxQ.push_back(j);

            if (j >= n) {
                minn.push_back(mat[i][minQ.front()]);
                maxn.push_back(mat[i][maxQ.front()]);
            }
        }
        rowMax.push_back(move(maxn));
        rowMin.push_back(move(minn));
    }

    vector<vector<int> > maxMat(a - n + 1, vector<int> (b - n + 1)), 
        minMat(a - n + 1, vector<int> (b - n + 1));

    for (int j = 0; j < b - n + 1; ++j) {
        deque<int> minQ, maxQ;
        for (int i = 0; i < a; ++i) {
            if (!minQ.empty() && i - minQ.front() >= n) {
                minQ.pop_front();
            }
            while (!minQ.empty() && rowMin[i][j] < rowMin[minQ.back()][j]) {
                minQ.pop_back();
            }
            minQ.push_back(i);

            if (!maxQ.empty() && i - maxQ.front() >= n) {
                maxQ.pop_front();
            }
            while (!maxQ.empty() && rowMax[i][j] > rowMax[maxQ.back()][j]) {
                maxQ.pop_back();
            }
            maxQ.push_back(i);

            if (i >= n - 1) {
                maxMat[i - n + 1][j] = rowMax[maxQ.front()][j];
                minMat[i - n + 1][j] = rowMin[minQ.front()][j];
            }
        }
    }
    int res = 1e9 + 7;
    for (int i = 0; i < a - n + 1; ++i) {
        for (int j = 0; j < b - n + 1; ++j) {
            res = min(res, maxMat[i][j] - minMat[i][j]);
        }
    }
    printf("%d\n", res);
}