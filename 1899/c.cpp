#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

typedef long long ll;

int t, n, a[N];


void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> a[i];

	ll curr = a[0];
	ll ans = a[0];
	for (int i = 1; i < n; i++) {
		if (abs(a[i - 1]) % 2 != abs(a[i]) % 2) {
			curr = max(0ll, curr) + a[i];
		} else {
			curr = a[i];
		}
		ans = max(ans, curr);
	}

	// for (int i = 0; i < n; i++) 
	// 	cout << dp[i] << " ";
	// cout << '\n';

	cout << ans << '\n';

}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}