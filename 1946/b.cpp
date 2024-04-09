#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;


int main() {
	cin.tie(0)->sync_with_stdio(0);

	vector<ll> pow(200005);

	pow[0] = 1;
	for (int i = 1; i < (int) pow.size(); i++) {
		pow[i] = (pow[i - 1] * 2) % MOD;
	}

	int t; cin >> t;
		
	while (t--) {
		int n, k; cin >> n >> k;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		ll sum = 0;
		ll window = 0;
		ll tot = 0;
		for (int i = 0; i < n; i++) {
			tot += a[i];
			sum += a[i];
			if (sum < 0) sum = 0;
			window = max(window, sum);
		}
		window %= MOD;
		tot %= MOD;

		cout << ((pow[k] * window) % MOD + (tot - window + MOD) % MOD + MOD) % MOD << '\n';
	}
	return 0;
}
