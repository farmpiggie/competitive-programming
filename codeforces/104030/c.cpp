#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1' || (i - 1 >= 0 && s[i-1] == '1') || (i - 2 >= 0 && s[i-2] == '1'))
        {
            ans++;
        }

    }
    cout << ans << "\n";
}