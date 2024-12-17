#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main() {
	int t; cin >> t;
	while(t--) {
		int n, k; cin >> n >> k;
		vector<int> a(n), b(n);
		for (int& x : a) cin >> x;
		for (int& x : b) cin >> x;
 
		int lo = 0, hi = 1e9;
		while (lo < hi) {
			int mid = lo + (hi - lo) / 2;
			ll target = 0;
			for (int i = 0; i < n; i++) {
				// # of times to operate so all numbers > mid are consumed
				target += max(0, (a[i] - mid + b[i] - 1) / b[i]);
			}

			if (target > k) {
				lo = mid + 1;
			} else {
				hi = mid;
			}
		}
		ll ans = 0;
		vector<ll> c(n);
		for (int i = 0; i < n; i++) {
			int ops = max(0, (a[i] - lo + b[i] - 1) / b[i]); 
			k -= ops;
			ans += 1ll * a[i] * ops - 1ll * ops * (ops - 1) / 2 * b[i];
			c[i] = max(0ll, 1ll * a[i] - 1ll * ops * b[i]);
		}	
		sort(c.rbegin(), c.rend());
		for (int i = 0; i < min(k, n); i++) {
			ans += c[i];
		}
		cout << ans << '\n';
	}
	return 0;
}
