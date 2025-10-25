// [p] [p] [p] [prefix of p]
// q = 2
//
//
// -1e9 1e9 2 -> p
// [2] [2] [2] -1e9
//
// [p] [p] [p] [prefix of p]
//
// sum(p) = q
//
//
//
//
//
// allow x = floor(n / p)
// if (x * p == n && q * x != m) return false;
//
// if ((x - 1) * q > m) return false
#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n, m, p, q;
                cin >> n >> m >> p >> q;
                int x = n / p;
                cout << ((x * p == n && q * x != m) ? "NO": "YES") << '\n';
        }
}
