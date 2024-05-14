// greedily order in 1, 2, ..., n, 1, 2, ... n?
// we could have a case liek 2, 1, 3, ...n, 2
// first value should be the one that occurs the most often, and sorted as such
// answer = # of numbers in said order... - n + 1?
// binary search on the length of said order? 
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; ll k; cin >> n >> k;
		vector<ll> a(n);
		for (ll& x : a) cin >> x;
		sort(a.begin(), a.end());
		reverse(a.begin(), a.end());
		ll lo = 0, hi = (ll) (1e18);
		ll ans = 0;
		while (lo <= hi) {
			ll mi = lo + (hi - lo) / 2;
			ll req = 0;
			for (int i = 0; i < n; i++) {
				req += max(0ll, (mi / n) - a[i] + ((mi % n > i) ? 1 : 0));
			}
			if (req <= k) {
				ans = mi - n + 1;
				lo = mi + 1;
			} else {
				hi = mi - 1;
			}
		}
		cout << ans << '\n';

	}
	return 0;
}
