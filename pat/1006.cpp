#include <bits/stdc++.h>
using namespace std;

struct Time {
    int hour;
    int minute;
    int second;

    bool operator< (const Time &rhs) {
        if (hour != rhs.hour) {
            return hour < rhs.hour;
        } else if (minute != rhs.minute) {
            return minute < rhs.minute;
        } else {
            return second < rhs.second;
        }
    }

};

struct Recording {
    string id;
    Time signIn;
    Time signOut;
};

int twoCharToInt(string s)
{
    return (s[0] - '0') * 10 + (s[1] - '0');
}

void stringToTime(string s, Time *t)
{
    t->hour = twoCharToInt(s.substr(0, 2));
    t->minute = twoCharToInt(s.substr(3, 2));
    t->second = twoCharToInt(s.substr(6, 2));
}

vector<Recording> records;
int main()
{
    int m;
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        string id, signin, signout;
        cin >> id >> signin >> signout;
        Recording r;
        r.id = id;
        stringToTime(signin, &r.signIn);
        stringToTime(signout, &r.signOut);
        records.emplace_back(r);
    }
    Recording firstIn = records[0], lastOut = records[0];
    for (int i = 1; i < m; ++i) {
        if (records[i].signIn < firstIn.signIn) {
            firstIn = records[i];
        }

        if (lastOut.signOut < records[i].signOut) {
            lastOut = records[i];
        }
    }
    cout << firstIn.id << " " << lastOut.id;

    return 0;
}