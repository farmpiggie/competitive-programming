/*
for each region, we have one sorted list
binary search for this answer.

for each row, store monotonically decreasing values in pairs of the form
{x, i}, where x is the value of the river and i is the country index
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vl vector<ll>
#define v2l vector<vl>
#define pll pair<ll, ll>
#define vp vector<pll>
#define v2p vector<vp>

// struct query {
// 	int r;
// 	char o;
// 	int c;
// };

int main() {
	int t; t = 1;
	while (t--) {
		int n, k, q; cin >> n >> k >> q;
		v2l a(n, vl(k, 0)); // a[country][region]
		for (auto& x : a) for (ll& y : x) cin >> y;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < k; j++) {
				a[i][j] |= a[i - 1][j];
			}
		}

		// for (int i = 0; i < n; i++) {
		// 	for (int j = 0; j < k; j++) {
		// 		cout << a[i][j] << " ";
		// 	}
		// 	cout << '\n';
		// }

		// v2p small(k, vp(0)), big(k, vp(0)); // monotonically decreasing, monotonically increasing.
		// for (int j = 0; j < k; j++) {
		// 	small[j].push_back({a[0][j], 0});
		// 	big[j].push_back({a[0][j], 0});
		// 	for (int i = 1; i < n; i++) {
		// 		if (a[i][j] < small[j].back().first) { // monotonically decreasing
		// 			small[j].push_back({a[i][j], 1ll * i}); // value at a[i][j], country it belongs to
		// 		}
		// 		if (a[i][j] > big[j].back().first) { // monotonically increasing
		// 			big[j].push_back({a[i][j], 1ll * i}); 
		// 		}
		// 	}
		// 	reverse(small[j].begin(), small[j].end()); // allow us to binary search
		// }

		// vector<query> queries(q);
		// for (int i = 0; i < q; i++) cin >> queries[i].r >> queries[i].o >> queries[i].c;

		while (q--) {
			int m; cin >> m;
			int low_end = 0, high_end = n - 1;
			for (int i = 0; i < m; i++) {
				int r, c; char o;
				cin >> r >> o >> c;
				--r;
				int ans = (o == '<' ? -1 : n + 1);
				int lo = 0, hi = n - 1;
				while (lo <= hi) {
					int mi = lo + (hi - lo) / 2;
					if (o == '>') {
						if (a[mi][r] > c) {
							ans = min(ans, mi);
							hi = mi - 1;
						} else {
							lo = mi + 1;
						}
					} else {
						// cout << "mi: " << mi << '\n';
						// cout << a[mi][r] << " " << c << '\n';
						if (a[mi][r] < c) {
							ans = max(ans, mi);
							lo = mi + 1;
						} else {
							hi = mi - 1;
						}
					}
				}
				// cout << "ans: " << ans << '\n';
				// ans = biggest index where a[mi][r] < c or smallest index where a[mi][r] > c
				if (ans == -1 || ans == n + 1) { // impossible
					low_end = n + 1;
					high_end = -1;
				}
				if (o == '<') high_end = min(high_end, ans);
				else low_end = max(low_end, ans);
				// cout << "range: " << low_end << " " << high_end << '\n';
			}
			if (low_end <= high_end) cout << low_end + 1 << '\n';
			else cout << "-1\n";
		}

	}
	return 0;
}