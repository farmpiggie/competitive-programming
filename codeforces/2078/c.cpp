/*
 * sorting and alternating always leads to some x <= 1e18
 *
 * how can we guarantee it is unique?
 *
 * 6 - 4 + 3 - 1 = x, x = 4.
 *
 * what if x isn't distinct?
 *
 *
 * x - 6 + 3 - 1 = 4?
 *
 * reason this always works:
 * sum of all terms after (x - a0) <= a1.
 *
 * x - 8 + 4 - 1 = 6
 * 
 * 8 - 6
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		n *= 2;
		vector<int> a(n);
		for (int &x : a) cin >> x;

		sort(a.rbegin(), a.rend());
			
		ll ans = a[0] + a[1];
		for (int i = 2; i < n; i += 2) {
			ans += (a[i + 1] - a[i]);
		}
		cout << a[1] << " " << ans << " " << a[0] << " ";
		for (int i = 2; i < n; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
	}
}

