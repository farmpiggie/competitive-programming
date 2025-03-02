#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;


ll add(ll x, ll y) {
	x %= MOD; y %= MOD;
	if (x < 0) x += MOD;
	if (y < 0) y += MOD;
	return (x + y) % MOD;
}

ll mul(ll x, ll y) {
	x %= MOD; y %= MOD;
	if (x < 0) x += MOD;
	if (y < 0) y += MOD;
	return x * y % MOD;
}

ll sub(ll x, ll y) {
	x %= MOD; y %= MOD;
	if (x < 0) x += MOD;
	if (y < 0) y += MOD;
	return (x - y + MOD) % MOD;
}

ll binpow(ll x, ll y) {
	if (y == 0) return 1;
	ll res = binpow(x, y / 2);
	res = mul(res, res);
	if (y & 1) res = mul(res, x);
	return res;
}

ll inv(ll x) {
	return binpow(x, MOD - 2);
}

ll two_inv = inv(2), six_inv = inv(6);

ll sum(ll x) {
	return mul(x, x + 1) * two_inv % MOD;
}

ll sum(ll l, ll r) {
	return sub(sum(r), sum(l - 1));
}

ll sum2(ll x) {
	return mul(x, mul(x + 1, 2 * x + 1)) * six_inv % MOD;
}

ll sum2(ll l, ll r) {
	return sub(sum2(r), sum2(l - 1));
}

ll rev(ll n, ll p) {
	ll res = 0;
	vector<ll> a;
	while (n > 0) {
		a.push_back(n % p);
		n /= p;
	}
	reverse(a.begin(), a.end());
	ll mult = 1;
	for (ll x : a) {
		res = add(res, mul(x, mult));
		mult = mul(mult, p);
	}
	return res;
}

// sqrt rounded down
ll mysqrt(ll x) {
	ll l = 1, r = x;
	ll ans = 1;
	while (l <= r) {
		ll m = (l + r) / 2;
		if (m * m <= x) {
			ans = max(ans, m);
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	return ans;
}

// find biggest base p s.t. floor(n / p) = x.
ll find(ll n, ll x) {
	int l = 1, r = n;
	int ans = l;
	while (l <= r) {
		int m = (l + r) / 2;
		if (n / m >= x) {
			ans = max(ans, m);
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	return ans;
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		ll n, k; cin >> n >> k;
		ll ans = 0;
		ll sqrt = mysqrt(n);
		// 2 -> sqrt(n): compute naively 
		for (int p = 2; p <= min(sqrt, k); p++) {
			ans = add(ans, rev(n, p));
		}

		// sqrt(n) + 1 to n: compute sum of power
		if (k > sqrt) {
			int l = min(k, sqrt + 1);
			int r = min(k, n);
			ans = add(ans, mul(n, sum(l, r)));
			
			// check which bases correspond to values of msb = floor(n / p)
			for (int msb = 1; msb <= sqrt; msb++) {
				int r = min(k, find(n, msb));
				int l = max(sqrt, find(n, msb + 1)) + 1;
				if (l > r) continue;
				ans = sub(ans, mul(msb, sum2(l, r)));
				ans = add(ans, mul(msb, r - l + 1));
			}
		}

		// n + 1 to k: add n
		ans = add(ans, mul(n, max(0ll, k - n)));
		cout << ans << '\n';
	}
}


