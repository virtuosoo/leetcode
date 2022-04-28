#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int res = a + b, tmpres = abs(res);
    vector<int> num;
    while (tmpres) {
        num.push_back(tmpres % 10);
        tmpres /= 10;
    }
    if (res < 0) {
        cout << "-";
    }

    if (res == 0) {
        cout << "0\n";
        return 0;
    }
    for (int i = num.size() - 1; i >= 0; --i) {
        if (i % 3 == 2 && i != num.size() - 1) {
            cout << ",";
        }
        cout << num[i];
    }
    cout << '\n';
    
}