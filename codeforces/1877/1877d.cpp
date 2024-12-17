#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int MOD = 998244353;

ll pow2[100005];
vector<vector<int>> factors(100005);

void solve() {
	int n; cin >> n;
	vector<int> arr(n);
	vector<pii> sorted(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sorted[i] = {arr[i], i};
	}

	sort(sorted.begin(), sorted.end());
	reverse(sorted.begin(), sorted.end());

	ll ans = 0;
	vector<bool> marked(n, 0);
	int c = 0;
	for (int i = 0; i < n; i++) {
		pii p = sorted[i];
		ll val = (ll) p.first;
		int index = p.second + 1;
		int prev_c = 0;
		cout << val << " " << index << endl;
		for (int factor : factors[index]) {
			cout << "factor: " << factor << endl;
			if (!marked[factor]) {
				marked[factor] = true;
				c++;
			}
		}
		cout << "c:" << c << endl;
		int gw = (pow2[n - prev_c] - pow2[n - c] + MOD) % MOD;

		ll count = (pow2[n - c] + MOD - 1) % MOD;
		ll addition = (val * count) % MOD;

		// calculate using 2^(n - c) - 1
		cout << "adding: " << addition << endl;
		ans = (ans + addition) % MOD;
	}

	cout << ans << endl;


}


int main() {
	// precompute 2^x for x <= 10^5
	pow2[0] = 1;
	for (int i = 1; i <= 100001; i++) {
		pow2[i] = (pow2[i - 1] * 2) % MOD;
	}
	// precompute all factors
	for (int i = 1; i <= 100000; i++) {
		for (int j = 1; j * i <= 100000; j++) {
			factors[j * i].push_back(i);
		}
	}

	int t = 1; // cin >> t;
	while (t--) solve();
	return 0;
}