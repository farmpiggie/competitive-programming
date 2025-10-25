#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int mn = 0;
    vector<int> l(n), r(n);
    for (int i = 1; i < n; i++)
    {
        if (a[i] >= a[i-1])
        {
            l[i] = a[i] - a[mn];
        } else
        {
            mn = i;
            l[i] = 0;
        }
    }

    mn = n - 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] >= a[i + 1])
        {
            r[i] = a[i] - a[mn];
        } else
        {
            mn = i;
            r[i] = 0;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, min(l[i], r[i]));
    }

    cout << ans << "\n";
}