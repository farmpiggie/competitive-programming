#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll MOD = 1e9 + 7;

ll binpow(ll x, ll y) {
        if (y == 0) return 1;
        ll res = binpow(x, y / 2);
        res = res * res % MOD;
        if (y & 1) res = res * x % MOD;
        return res;
}

ll inv(ll x) {
        return binpow(x, MOD - 2);
}

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                ll a, b, k; cin >> a >> b >> k;
                ll n = k * (a - 1) + 1;

                ll m = 1;
                for (ll i = n; i > n - a; i--) {
                        m = m * (i % MOD) % MOD;
                }
                for (int i = 1; i <= a; i++) {
                        m = m * inv(i) % MOD;
                }

                m = (m * k % MOD * (b - 1) % MOD + 1) % MOD;
                n %= MOD;

                cout << n << " " << m << '\n';
        }
}
