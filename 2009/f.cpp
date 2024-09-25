#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, q; cin >> n >> q;
		vector<ll> a(n);
		for (ll& x : a) cin >> x;

		vector<ll> psum(2 * n);
		psum[0] = a[0];
		for (int i = 1; i < 2 * n; i++) {
			psum[i] = psum[i - 1] + a[(i % n)];
		}

		while (q--) {
			ll l, r; cin >> l >> r;
			ll ans = 0;
			l--; r--;

			// cout << "full segments: " << (r / n - l / n - 1) << '\n';

			ans += 1ll * (r / n - l / n - 1) * psum[n - 1]; // full segments

			// cout << "ans: " << ans << '\n';

			// left remainder

			int l_length = n - (l % n); // at most n
			int l_end = l / n + n - 1; // at most (n - 1) + n - 1 = 2 * n - 2
			int l_start = l_end - l_length; // range is (l_start, l_end] for a total length of len

			// cout << "left: " << l_start << " " << l_end << '\n';

			assert(l_end < 2 * n);
			ans += psum[l_end];
			if (l_start >= 0) ans -= psum[l_start];

			// cout << "ans: " << ans << '\n';

			// right remainder
			int r_length = r % n + 1; // at most n
			int r_start = r / n - 1; // at most n - 1 - 1 = n - 2
			int r_end = r_start + r_length; // at most n - 2 + n = 2 * n - 2
			assert(r_end < 2 * n);
			ans += psum[r_end];
			if (r_start >= 0) ans -= psum[r_start];

			// cout << "right: " << r_start << " " << r_end << '\n';


			cout << ans << '\n';

		}

	}
	return 0;
}