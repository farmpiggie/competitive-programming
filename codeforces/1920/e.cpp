#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD (ll) 998244353
#define MAXN 2505
#define pii pair<int, ll> // index, value

ll dp[MAXN][MAXN] = {};
vector<int> divisors[MAXN] = {{}};

int t, n, k;

void precompute() {
	for (int i = 1; i <= 2500; i++) {
		for (int j = 1; j <= (int) sqrt(i); j++) {
			if (i % j == 0) {
				divisors[i].push_back(j);
				if (j * j != i) {
					divisors[i].push_back(i / j);
				}
			} 
		}
		sort(divisors[i].begin(), divisors[i].end());
	}
}

void solve() {
	cin >> n >> k;
	
	for (int j = 0; j < k; j++) {
		dp[0][j] = 1; // one way to create a string with 0 good substrings with ending zeros = j
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < k; j++) {
			dp[i][j] = 0;
		}
		for (int x = 0; x < i; x++) {
			for (int j : divisors[i - x]) { 
				int y = (i - x) / j - 1;
				if (y + j <= k) {
					dp[i][j - 1] = (dp[i][j - 1] + dp[x][y]) % MOD;
				}
			}
		}
	}

	ll ans = 0;
	for (int j = 0; j < k; j++) {
		ans = (ans + dp[n][j]) % MOD;
	}
	cout << ans << '\n';
}

int main() {
	precompute();
	cin >> t;
	while (t--) solve();
	return 0;
}