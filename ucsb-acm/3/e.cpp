/*
 * we can enumerate through several possibilities
 * separate this into:
 * 1. edges on path from a to b (of length k)
 *      a. # of edges on path
 *              x. enumerate through (1...n - 1)
 *              y. the # of possibilities for path of length n is: (n - 2) choose (k - 1)
 *      b. weight of edges on path
 *              x. the # of ways to split m into k segments: (m - 1) choose (k - 1)
 * 2. forest of nodes not on said path
 *      a. something called Cayley's # calculates # of forest with x vertices with nodes (1...y) in diff trees
 *      b. assigning each forest to a node is (k + 1) ^ x.
 *      c. length of each edge can be between 1 to m, so multiply result by m ^ edges.
 */
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 1e9 + 7;
vector<ll> f = {1};

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

ll fac(int x) {
        while ((int) f.size() < x + 1) {
                f.push_back(f.back() * (int) f.size() % MOD);
        }
        return f[x];
}

ll nCk(int n, int k) {
        return fac(n) * inv(fac(k)) % MOD * inv(fac(n - k)) % MOD;
}

ll cayley(int x, int y) {
        if (x == y) return 1;
        return 1ll * y * binpow(x, x - y - 1) % MOD;
}

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int n, m, a, b; cin >> n >> m >> a >> b;
        ll ans = 0;
        for (int k = 1; k < n; k++) {
                if (k > m) break;
                ll res = fac(n - 2) * inv(fac(n - 2 - (k - 1))) % MOD * nCk(m - 1, k - 1) % MOD * binpow(m, n - k - 1) % MOD * cayley(n, k + 1) % MOD;
                ans = (ans + res) % MOD;
        }
        cout << ans << '\n';
}


