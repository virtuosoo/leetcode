#include <bits/stdc++.h>

class String
{
public:
    String (const char * pStr = "")
    {
        if (pStr == nullptr) {
            _pStr = new char[1];
            _pStr[0] = '\0';
        } else {
            _pStr = new char[strlen(pStr) + 1];
            strcpy(_pStr, pStr);
        }
    }

    String (const String& s):
        _pStr(s._pStr) {}
    
    String& operator= (const String& s)
    {
        if (this != &s) {
            _pStr = s._pStr;
        }
        return *this;
    }

    ~String()
    {
        printf("~String() called\n");
        if (_pStr) {
            delete[] _pStr;
            _pStr = nullptr;
        }
    }
private:
    char *_pStr;
};

void f()
{
    String s1("hello");
    String s2(s1);
    printf("????");
}
int main()
{
    f();
    return 0;
}