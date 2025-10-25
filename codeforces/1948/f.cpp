/*
 * each bag has some amt of gold and silver coins
 * gold = 1, silver = 0 or 1
 * given some range [l, r], compute probability that sum(coins in range) > sum(all other coins)
 *
 * let k = (gold coins inside - gold coins outside)
 * x = # of silver coins with 1 inside segment
 * y = # of silver coins with 1 outside segment
 *
 * x - y + k > 0 must be met
 * if we make all silver inside segment = 1, all silver outside segment = 0,
 * then if we "flip" either coin, (x - y) always decreases by 1.
 *
 * start with n = (k + x) value.
 * every silver coin has a 1/2 chance of reducing this by 1.
 * # of ways to not break inequality is sum((m choose i)) for i = [0, n - 1]
 * answer is therefore sum / (2 ^ m)
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll MOD = 998244353;

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
        int n, q; cin >> n >> q;
        vector<int> a(n), b(n);

        ll gold = 0, silver = 0;
        for (int &x : a) {
                cin >> x;
                gold += x;
        }
        for (int &x : b) {
                cin >> x;
                silver += x;
        }

        vector<ll> pgold(n), psilver(n); // psum of gold, silver
        for (int i = 0; i < n; i++) {
                pgold[i] = a[i] + (i ? pgold[i - 1] : 0);
        }
        for (int i = 0; i < n; i++) {
                psilver[i] = b[i] + (i ? psilver[i - 1] : 0);
        }

        auto rangesum = [&](int x, int y, const vector<ll>& a) -> ll {
                return a[y] - (x ? a[x - 1] : 0);
        };

        vector<ll> fac(silver + 1), invfac(silver + 1);
        fac[0] = 1;
        invfac[0] = inv(fac[0]);
        for (int i = 1; i <= silver; i++) {
                fac[i] = fac[i - 1] * i % MOD;
                invfac[i] = inv(fac[i]);
        }

        vector<ll> sum(silver + 1, 0); // sum[i] = psum of m choose i from [0, i]
        sum[0] = 1;
        for (int i = 1; i <= silver; i++) {
                ll res = fac[silver] * invfac[i] % MOD * invfac[silver - i] % MOD; // m choose i
                sum[i] = (sum[i - 1] + res) % MOD;
        }

        ll pow2 = binpow(2, silver);

        while (q--) {
                int l, r; cin >> l >> r;
                --l; --r;
                ll k = 2 * rangesum(l, r, pgold) - gold; // inside - outside = inside - (total - inside)
                ll x = rangesum(l, r, psilver); // silver inside range
                ll val = min(k + x - 1, silver); // can switch up to this many off.
                if (val < 0) cout << 0 << ' ';
                else cout << sum[val] * inv(pow2) % MOD << ' ';
        }
        cout << '\n';
}
