#include <iostream>
#include <vector>
using namespace std;
int stringToInt(std::string s, size_t start, size_t end)
{
    int f = 1, res = 0;
    if(s[start] == '-'){
        f = -1;
        start += 1;
    }
    for(int i = start; i <= end; ++i){
        res = 10 * res + s[i] - '0';
    }
    return res * f;
}
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int x_1, y_1, x_2, y_2;
        size_t idx = num1.find('+');
        x_1 = stringToInt(num1, 0, idx - 1);
        y_1 = stringToInt(num1, idx + 1, num1.length() - 2);
        //cout << x_1 << " " << y_1 << '\n';
        idx = num2.find('+');
        x_2 = stringToInt(num2, 0, idx - 1);
        y_2 = stringToInt(num2, idx + 1, num2.length() - 2);
        //cout << x_2 << " " << y_2 << '\n';
        int a = x_1 * x_2 - y_1 * y_2, b = (x_1 * y_2 + x_2 * y_1);
        string ans = to_string(a) + "+" + to_string(b) + "i";
        return ans;
    }
};