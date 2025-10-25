#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    
    int sm = 0;
    int mo = 0;
    int nm = 1;
    while (nm < c)
    {
        sm += b * nm;
        
        while (sm >= a)
        {
            nm++;
            sm -= a;
        }
        mo++;
    }
    
    cout << mo << "\n";
    
    
    
 return 0;
}

