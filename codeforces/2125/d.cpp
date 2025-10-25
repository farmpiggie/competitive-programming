#include <iostream>
#include <vector>
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
	cin.tie(0)->sync_with_stdio(0);
	int n, m; cin >> n >> m;
	vector<vector<pair<int, ll>>> arr(m + 1); // arr[right endpt] = {length of segment, p * inv(q) % MOD}

	vector<ll> psum(m + 1, 1);
	for (int i = 0; i < n; i++) {
		int l, r; ll p, q;
		cin >> l >> r >> p >> q;

		ll mul = p * inv(q) % MOD;
		arr[r].push_back({r - l + 1, mul});
		psum[l] = psum[l] * (1 - mul + MOD) % MOD; // (1 - p/q)
	}

	for (int i = 1; i <= m; i++) {
		psum[i] = psum[i - 1] * psum[i] % MOD;
	}

	vector<ll> dp(m + 1, 0);
	dp[0] = 1;
	for (int i = 1; i <= m; i++) {
		for (auto [len, mul] : arr[i]) {
			int j = i - len; 

			// dp[j] * (psum[i] / psum[j]) / (1 - mul) * mul
			dp[i] = (dp[i] + dp[j] * psum[i] % MOD * inv(psum[j]) % MOD * inv((1 - mul + MOD) % MOD) % MOD * mul % MOD) % MOD;
		}
	}
	cout << dp[m] << '\n';
	return 0;
}
