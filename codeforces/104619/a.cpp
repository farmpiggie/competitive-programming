#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    string m;
    m.push_back(s[5]);
    m.push_back(s[6]);
    string d;
    d.push_back(s[8]);
    d.push_back(s[9]);
    int cm = stoi(m);
    int cd = stoi(d);
    //september has 30 days
    if (cm < 9)
    {
        cout << "GOOD";
    } else if (cm >= 10)
    {
        cout << "TOO LATE";
    } else if (cm == 9)
    {
        if (cd < 17)
        {
            cout << "GOOD";
        } else
        {
            cout << "TOO LATE";
        }
    }
 return 0;
}

