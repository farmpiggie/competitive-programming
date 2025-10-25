#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a (n, vector<int> (m));
    vector<vector<int>> b (n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    
    vector<int> l(n, -1), r(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 1)
            {
                b[i].push_back(j);
            }
        }
    }
    
    
    for (int k = 0; k < n; k++) //trips across the thing
    {
        int rt = 0;
        bool ok = 0;
        for (int i = 0; i < n; i++)
        {
            int drt = rt;
            if (b[i].empty() || rt > b[i].back())
            {
                continue;
            }
            for (; rt <= b[i].back(); rt++)
            {
                if (a[i][rt] == 1)
                {
                    a[i][rt] = 0;
                    ok = 1;
                }
            }
            rt--;
            
            while (!b[i].empty() && b[i].back() >= drt)
            {
                b[i].pop_back();
            }
        }
        
        if (!ok)
        {
            cout << k << "\n";
            return 0;
        }
    }

    cout << n << "\n";
    
 return 0;
}

