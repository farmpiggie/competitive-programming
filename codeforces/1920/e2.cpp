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
	vector<vector<pii>> pre(n, vector<pii>(0)); // sorted pairs 
	for (int j = 0; j < k; j++) {
		dp[0][j] = 1; // one way to create a string with 0 good substrings with ending zeros = j
	}

	pre[0].push_back({0, dp[0][0]});
	for (int j = 1; j < k; j++) {
		auto p = pre[0].back();
		pre[0].push_back({j, (p.second + dp[0][j]) % MOD});
	}

	cout << "pre[0]\n";
	for (auto p : pre[0]) {
		cout << '(' << p.first << ", " << p.second << ")\t";
	}
	cout << '\n';


	for (int i = 1; i <= n; i++) {
		cout << "i: " << i << '\n';
		for (int j : divisors[i]) { // all divisors including zero
			// consider case where we come from zero cases
			if (j - 1 >= k) continue;
			cout << "j: " << j - 1 << '\n';

			// special case of zeros, then only one one, then a bunch of zeros.
			cout << "considering special case: adding one\n";
			dp[i][j - 1] = 1;

			if (j - 1 == 0) dp[i][j - 1] = dp[i - 1][j - 1] + 1; // adding one for 

			// if (i == 2 && j == 1) {
			// 	cout << "dp[2][0] before divisor: " << dp[i][j - 1] << '\n';
			// }

			// general case.
			cout << "checking divisors now!" << '\n';
			cout << "divisor: " << j << '\n';
			auto it = lower_bound(pre[i / j].begin(), pre[i / j].end(), make_pair(k - j + 1, 0ll));
			if (it != pre[i / j].end()) {
				cout << "iterator: " << it->first << " " << it->second << '\n';
				cout << "adding " << it->second << "\n";
				dp[i][j - 1] = (dp[i][j - 1] + it->second % MOD);
			} else {
				cout << "iterator not found.\n";
			}

			if (pre[i].size() == 0) {
				pre[i].push_back({j - 1, dp[i][j - 1]});
			} else {
				auto p = pre[i].back();
				pre[i].push_back({j - 1, (p.second + dp[i][j - 1]) % MOD});
			}	

			cout << "value of dp[" << i << "][" << j - 1 << "]: " << dp[i][j - 1] << '\n';
		}

		cout << "pre[" << i << "]\n";
		for (auto p : pre[i]) {
			cout << '(' << p.first << ", " << p.second << ")\t";
		}
		cout << '\n';
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