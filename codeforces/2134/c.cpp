#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int &x : a) cin >> x;

		ll ans = 0;
		for (int i = 2; i < n; i += 2) {
			if (a[i - 2] > a[i - 1]) {
				ans += a[i - 2] - a[i - 1];
				a[i - 2] = a[i - 1];
			}
			// a[i] + a[i - 2] = a[i - 1]
			// a[i] = a[i - 1] - a[i - 2]
			if (a[i] > a[i - 1] - a[i - 2]) {
				ans += a[i] - (a[i - 1] - a[i - 2]);
				a[i] = a[i - 1] - a[i - 2];
			}
		}

		// last two numbers
		if (n % 2 == 0) { // last number is even
			if (a[n - 2] > a[n - 1]) {
				ans += a[n - 2] - a[n - 1];
			}
		} else {
			if (a[n - 1] > a[n - 2]) {
				ans += a[n - 1] - a[n - 2];
			}
		}


		cout << ans << '\n';
	}
}
