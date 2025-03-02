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

ll two_inv = inv(2);
ll six_inv = inv(6);

ll sum(ll x) {
	return x * (x + 1) % MOD * two_inv % MOD;
}

ll sum(ll l, ll r) {
	return (sum(r) - sum(l - 1) + MOD) % MOD;
}

ll sum2(ll x) {
	return x * (x + 1) % MOD * (2 * x + 1) % MOD * six_inv % MOD;
}

ll sum2(ll l, ll r) {
	return (sum2(r) - sum2(l - 1) + MOD) % MOD;
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
		res = (res + (x * mult) % MOD) % MOD;
		mult = (mult * p) % MOD;
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
			ans = (ans + rev(n, p)) % MOD;
		}
		// sqrt(n) + 1 to n: compute sum of power
		if (k > sqrt) {
			int l = min(k, sqrt + 1);
			int r = min(k, n);
			ans = (ans + (n * sum(l, r) % MOD)) % MOD;
			
			// check which bases correspond to values of msb = floor(n / p)
			for (int msb = 1; msb <= sqrt; msb++) {
				int r = min(k, find(n, msb));
				int l = max(sqrt, find(n, msb + 1)) + 1;
				if (l > r) continue;
				ans = (ans - (msb * sum2(l, r) % MOD) + MOD) % MOD;
				ans = (ans + (msb * (r - l + 1) % MOD)) % MOD;
			}
		}

		// n + 1 to k: add n
		ans = (ans + (n * max(0ll, (k - n) % MOD) % MOD)) % MOD;
		cout << ans << '\n';
	}
}
