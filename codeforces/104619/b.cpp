#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll x, y;
    long double l, r;
    cin >> x >> y >> l >> r;
    l *= 100, r *= 100;
    x--,y--;
    //~ cout << fixed << setprecision(20) << l << " " << r << "\n";
    ll vx = roundl(l), vy = roundl(r);
    ll g1 = gcd(x,vx), g2 = gcd(y,vy);
    vx /= g1, x /= g1;
    vy /= g2, y /= g2;
    if (vx * y == vy * x)
    {
        cout << "SAME";
    } else if (vx * y < vy * x)
    {
        cout << "JAKARTA";
    } else
    {
        cout << "TAOYUAN";
    }
    cout << "\n";
 return 0;
}

