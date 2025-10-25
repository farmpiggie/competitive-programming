#include <bits/stdc++.h>

using namespace std;

int main()
{
    string x, y;
    cin >> x >> y;

    for (auto z : x)
    {
        if (z < '0' || z > '9')
        {
            cout << "NaN" << "\n";
            return 0;
        }
    }

    for (auto z : y)
    {
        if (z < '0' || z > '9')
        {
            cout << "NaN" << "\n";
            return 0;
        }

    }

    cout << stoi(x) - stoi(y) << "\n";
}