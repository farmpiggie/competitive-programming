#include <bits/stdc++.h>
using namespace std;

#define ll long long

// fighting negative rating opponent increases rating
// last remaining fighter will be the guy on the right


int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int& x : a) cin >> x;

		ll ans = a[n - 1] - a[n - 2];
		for (int i = 0; i < n - 2; i++) ans += a[i];
		cout << ans << '\n';

	}
	return 0;
}