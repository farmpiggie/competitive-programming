#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int K = 1e5 + 1;
const int LG = 20;
const ll MOD = 998244353;

vector<ll> f = {1};
ll fac(int x) {
	while ((int) f.size() < x + 1) {
		f.push_back(f.back() * f.size() % MOD);
	}
	return f[x];
}
		
ll binpow(ll x, ll y) {
	if (y == 0) return 1;
	else {
		ll res = binpow(x, y / 2);
		res = res * res % MOD;
		if (y % 2) res = res * x % MOD;
		return res;
	}
}

ll inv(ll x) {
	return binpow(x, MOD - 2);
}


int main() {
	vector<vector<int>> factors(K);
	for (int i = 1; i < K; i++) {
		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				factors[i].push_back(j);
				if (j * j != i) factors[i].push_back(i / j);
			}
		}
		factors[i].push_back(i); // itself
	}

	vector<vector<ll>> dp(LG, vector<ll>(K, 0));
	dp[0][1] = 1;
	for (int i = 1; i < LG; i++) {
		for (int j = 2; j < K; j++) {
			for (int k : factors[j]) {
				dp[i][j] = (dp[i][j] + dp[i - 1][j / k]) % MOD;
			}
		}
	}
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int k, n; cin >> k >> n;
		cout << n << ' '; // x = 1
		for (int x = 2; x <= k; x++) {
			// max length in x without a 1
			ll ans = 0;
			int len = 0;
			for (int i = 1; i < LG; i++) {
				if (dp[i][x] > 0) len = i;
				else break;
			}

			
			for (int i = 1; i <= len; i++) {
				ll mult = 1;
				for (int j = n + 1; j >= n - i + 1; j--) {
					mult = mult * j % MOD;
				}
				mult = mult * inv(fac(i + 1)) % MOD;
				ans = (ans + dp[i][x] * mult % MOD) % MOD;
			}
			cout << ans << ' ';
		}
		cout << '\n';
	}
}

