/*
 * define f(i, j) as answer for a given range [i, j]
 * platina will always call L or R
 * yuto always calls X to minimize max(f(L, X), f(X, R))
 * as we move X from left to right,
 * f(L, x) will be smaller up to a certain point, then f(x, R) will be smaller
 * we must find the boundary between these two
 *
 * if we can binary search on this boundary, we need to calculate f(i, j) in O(1)
 *
 * k consecutive non decreasing elements = k * (k + 1) / 2 non-decreasing subarrays
 * we can use prefix sums to calculate # of non-decreasing subsequences.
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, t; cin >> n >> t;
	vector<int> a(n);
	for (int& x : a) cin >> x;
	
	vector<array<int, 2>> b; // ranges of non-decreasing subarrays
	int l = 0;
	for (int r = 1; r < n; r++) {
		if (a[r - 1] > a[r]) {
			b.push_back({l, r - 1});
			l = r;
		} // otherwise continue
	}
	b.push_back({l, n - 1});
	
	vector<int> lt(n), rt(n);
	for (auto [x, y] : b) {
		for (int i = x; i <= y; i++) {
			lt[i] = x, rt[i] = y;
		}
	}

	vector<ll> pre(n, 0); // prefix sums for # of completely contained values
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j < b.size() && b[j][1] < i) {
			j++;
		}
		ll len = 0;
		if (b[j][1] == i) {
			len = b[j][1] - b[j][0] + 1;
		}
		pre[i] = len * (len + 1) / 2 + (i ? pre[i - 1] : 0);
	}

	auto f = [&](int i, int j) {
		if (i == j) return 1ll;
		ll res = pre[j] - (i ? pre[i - 1] : 0);
	//	if (i == 5 && j == 6) cout << "res before: " << res << '\n';
		if (res == 0) { // all i, j contained in a single one
			ll len = (j - i + 1);
			return len * (len + 1) / 2;
		} else {
			if (lt[i] != i) {
				// add partial
				ll orig = (rt[i] - lt[i] + 1);
				orig = orig * (orig + 1) / 2;
				ll len = (rt[i] - i + 1);
				len = len * (len + 1) / 2;
				res -= orig;
				res += len;
			}
			if (rt[j] != j) {
				ll len = j - lt[j] + 1;
				len = len * (len + 1) / 2;
				res += len;
			}
		}
		return res;
	};

	while (t--) {
		int l, r; cin >> l >> r;
		--l; --r;
		// bin search for largest x s.t. f(l, x) < f(x, r)
		int lo = l, hi = r;
		int ans = l;
		while (lo <= hi) {
			int mi = (lo + hi) / 2;
	//		if (l == 5 && r == 6) cout << mi << " " << f(l, mi) << " " << f(mi, r) << '\n';
			if (f(l, mi) < f(mi, r)) {
				ans = max(ans, mi);
				lo = mi + 1;
			} else {
				hi = mi - 1;
			}
		}
	//	if (l == 5 && r == 6) cout << "ans: " << ans << '\n' << f(l, ans) << " " << f(ans, r) << '\n';
		ll res = max(f(l, ans), f(ans, r)); 
		if (ans + 1 <= r) {
			ans++;
			res = min(res, max(f(l, ans), f(ans, r)));
		}
		cout << res << '\n';
	}
}

	



