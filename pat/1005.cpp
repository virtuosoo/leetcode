#include <bits/stdc++.h>
using namespace std;

const int N = 105;
string s;
string tras[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int main()
{
    cin >> s;
    if (s == "0") {
        cout << "zero\n";
        return 0;
    }
    vector<int> num;
    int sum = 0;
    for(int i = 0; i < s.length(); ++i) {
        sum += (s[i] - '0');
    }

    while (sum) {
        num.push_back(sum % 10);
        sum /= 10;
    }

    for (int i = num.size() - 1; i >= 0; --i) {
        cout << tras[num[i]];
        if (i == 0) cout << "\n";
        else cout << " ";
    }
    return 0;
}