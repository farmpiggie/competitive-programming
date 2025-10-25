#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(),b.end());
    
    cout << a[(n-1)/2] << " " << b[(n-1)/2] << "\n";
 return 0;
}

