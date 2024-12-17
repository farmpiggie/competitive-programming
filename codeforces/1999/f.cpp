/*
# of 1s > # of 0s.

x = # of ones
y = # of zeros
k = length of subsequence (odd)

ans = sum((x choose i) * (y choose k - i)) over i from k / 2 + 1 to k.
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 1e9 + 7;

vector<ll> fac = {1};
ll fact(ll n) {
	while (fac.size() <= n) {
		fac.push_back(fac.back() * fac.size() % MOD);
	}
	return fac[n];
}

ll binpow(ll x, ll y) {
	if (y == 0) return 1;
	else {
		ll res = binpow(x, y / 2);
		res = res * res % MOD;
		if (y % 2 == 1) res = res * x % MOD;
		return res;
	}
}

ll inv(ll x) {
	return binpow(x, MOD - 2);
}

// nCk = n! * inv(n!) * inv((n - k)!)
ll choose(ll n, ll k) {
	return fact(n) * inv(fact(k)) % MOD * inv(fact(n - k)) % MOD;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		int zeros = 0, ones = 0;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			if (x) ones++;
			else zeros++;
		}
		ll ans = 0;
		for (int x = k / 2 + 1; x <= min(k, ones); x++) {
			if (k - x < 0 || k - x > zeros) continue;
			ans = (ans + (choose(ones, x) * choose(zeros, k - x) % MOD)) % MOD;
		}
		cout << ans << '\n';
	}
	return 0;
}
