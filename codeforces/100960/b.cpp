#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, cx;
    cin >> n >> cx;
    vector<set<int>> st(2);
    for (int i = 0; i < n; i++)
    {
        int x, ty;
        cin >> x >> ty;
        st[ty].insert(x);
    }

    //initially the projectile is moving left
    int ct = 0;
    int p = cx;


    int ans = 0;
    while (!st[0].empty() || !st[1].empty())
    {
        // cout << p << " " << ct << "\n";
        if (ct == 1)
        {
            auto it = st[1].upper_bound(p);
            if (it == st[1].end()) 
            {
                cout << -1 << "\n";
                return 0;
            }
            p = *it;
            st[1].erase(it);
            ct ^= 1;
        } else
        {
            auto it = st[0].lower_bound(p);
            if (it == st[0].begin())
            {
                p = 0;
                ans++;
            } else
            {
                p = *prev(it);
                st[0].erase(prev(it));
            }
            ct ^= 1;
        }
    }

    cout << ans + (1 - ct) << "\n";

    return 0;
}