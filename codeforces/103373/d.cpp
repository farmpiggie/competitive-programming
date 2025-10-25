#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    cin >> n;

    cout << fixed << setprecision(8) << (long double)n/(2 * n - 2) << "\n";
    // long double ans = 0;
    // ans = ans + (long double)1/(n-1);
    // long double mu = (long double)(n - 2)/(n-1);
    // for (int k = n - 1; k >= 1; k--)
    // {
    //     ans = (ans + mu * 1/k);
    //     mu = mu * (long double)(k - 2)/k;
    // }

    // cout << fixed << setprecision(8) << ans << "\n";
}