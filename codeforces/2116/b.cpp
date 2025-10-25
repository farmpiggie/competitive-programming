#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 998244353;

ll binpow(ll x, ll y) {
        if (y == 0) return 1;
        ll ret = binpow(x, y / 2);
        ret = ret * ret % MOD;
        if (y & 1) ret = ret * x % MOD;
        return ret;
}

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n; cin >> n;
                vector<int> p(n), q(n);
                for (int &x : p) cin >> x;
                for (int &x : q) cin >> x;

                int maxp = 0, maxq = 0;

                vector<ll> ans(n);
                for (int i = 0; i < n; i++) {
                        if (p[i] > p[maxp]) maxp = i;
                        if (q[i] > q[maxq]) maxq = i;
                        if (p[maxp] > q[maxq]) {
                                ans[i] = (binpow(2, p[maxp]) + binpow(2, q[i - maxp])) % MOD;
                        } else if (q[maxq] > p[maxp]) {
                                ans[i] = (binpow(2, q[maxq]) + binpow(2, p[i - maxq])) % MOD;
                        } else if (q[i - maxp] > p[i - maxq]) { // take p[maxp]
                                ans[i] = (binpow(2, p[maxp]) + binpow(2, q[i - maxp])) % MOD;
                        } else {
                                ans[i] = (binpow(2, q[maxq]) + binpow(2, p[i - maxq])) % MOD;
                        }
                }

                for (ll x : ans) {
                        cout << x << ' ';
                }
                cout << '\n';
        }
}





                



