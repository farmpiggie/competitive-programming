#include <bits/stdc++.h>

using namespace std;
#define int long long

const int INF = 2e9 + 7;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;

    //cout << n << " " << k << "\n";

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int l = 1, r = INF;
    while (l < r)
    {
        //cout << l << " " << r << "\n";
        int m = (l + r)/2;
        vector<int> c;
        for (int i = 0; i < n; i++)
        {
            if (a[i] <= m/2)
            {
                c.push_back(i);       
            }
        }

        if (c.empty())
        {
            l = m + 1;
            continue;
        }
        int tmp = 0;
        int x = 0;
        bool ok = 0;
        for (int i = c[0]+1; i < c.back(); i++)
        {

            if (c[x + 1] == i)
            {
                tmp += ok;
                ok = 0;
                x++;
                continue;
            }
            if (!ok && a[c[x]] + a[i] <= m && a[c[x+1]] + a[i] <= m)
            {
                ok = 1;
            }
        }
        tmp += ok;
       // cout << "almost " << m << " " << c.size() << " " << tmp << "\n";
        if (c.size() > 1)
        {
            for (int i = 0; i < n; i++)
            {
                //cout << i << " " << c[0] << " " << c.back() << " " << a[i] + a[c[0]] << " " << a[i] + a[c.back()] << "\n";
                if ((i > c.back() || i < c[0]) && a[i] + a[c[0]] <= m && a[i] + a[c.back()] <= m)
                {
                    tmp++;
                    break;
                }
            }
        }
      //  cout << m << " " << c.size() << " " << tmp << "\n";
        if (c.size() + tmp >= k)
        {
            r = m;
        } else
        {
            l = m + 1;
        }
    }

    cout << l << "\n";
}