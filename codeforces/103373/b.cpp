#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e6 + 5;
typedef long long ll;
ll d[MAXN];
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i < MAXN; i++)
    {
        for (int j = 2*i; j < MAXN; j+=i)
        {
            d[j] += i;
        }
    }
    while (t--)
    {
        int n;
        cin >> n;
        if (d[n] > n)
        {
            cout << "abundant" << "\n";
        } else if (d[n] < n)
        {
            cout << "deficient" << "\n";
        } else
        {
            cout << "perfect" << "\n";
        }
    }
}