/*
dp[i] = min # of removals s.t. we end with a[i] and will NOT remove it

if we anchor a[i]...
consider j = nxt[i], k = nxt[j]
the next element x can be chosen from a[j...k) given x > a[i].

*/

#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

// kactl segtree
// init to zero for all elements
// max query, set update
struct Tree {
	typedef int T;
	static constexpr T unit = INT_MIN;
	T f(T a, T b) { return max(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int& x : a) cin >> x;
	
	vector<int> nxt(n, -1);
	list<int> dq; // monotonically decreasing indices
	for (int i = 0; i < n; i++) {
		while (!dq.empty() && a[i] > a[dq.back()]) {
			nxt[dq.back()] = i;
			dq.pop_back();
		}
		dq.push_back(i);
	}

	vector<pii> segments; // {start/end pos, index it represents}
	for (int i = 0; i < n; i++) {
		int j = nxt[i];
		if (j == -1) {
			segments.push_back({i + 1, i}); // we can realistically replace with any value we want.
			segments.push_back({n + 1, i}); // and it never closes.
			continue;
		}
		int k = nxt[j];
		if (k == -1) k = n + 1;
		segments.push_back({j, i});
		segments.push_back({k, i});
	}
	sort(segments.begin(), segments.end());
	

	vector<int> dp(n, INT_MIN);
	// base cases
	dp[0] = 1;
	for (int i = 1; i < (nxt[0] == -1 ? n : nxt[0]); i++) {
		dp[i] = 1; // we can remove all elements up to this one
	}

	Tree segtree(n + 1, 0); // for 1 to n
	// segtree[a[i]] = dp[i] if i is in the valid range

	int j = 0;
	for (int i = 1; i < n; i++) {
		while (j < (int) segments.size() && segments[j].first <= i) {
			int k = segments[j].second;
			if (segtree.query(a[k], a[k] + 1) == 0) {
				segtree.update(a[k], dp[k]); //
			} else {
				segtree.update(a[k], 0);
			}
			j++;
		}
		int best = segtree.query(0, a[i]);
		if (best > 0) dp[i] = max(dp[i], best + 1); // valid for > a[i]
	}
	int ans = dp[n - 1];
	int mx = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		if (a[i] > mx) ans = max(ans, dp[i]); // we can remove all elements after i
		mx = max(mx, a[i]);
	}
	cout << n - ans << '\n';
	return 0;
}
