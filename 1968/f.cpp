// how to tell whether or not an array is interesting?
// we can divide it into two segments if pre[n - 1] = 0
// otherwise look for a 0 within pre[i], and see if any values before this 0 correspond to pre[n - 1]
// can be done with preprocessing in O(logn)?, search through a sorted list
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, q; cin >> n >> q;
		vector<int> a(n);
		for (int& x : a) cin >> x;

		vector<int> pre(n, 0);
		map<int, vector<int>> occ;
		for (int i = 0; i < n; i++) {
			pre[i] = (i) ? pre[i - 1] ^ a[i] : a[i];
			occ[pre[i]].push_back(i);
		}


		while (q--) {
			int l, r; cin >> l >> r;
			--l; --r;
			int zero = (l) ? pre[l - 1] : 0;
			int end = pre[r] ^ zero;
			if (end == 0) {
				cout << "YES\n";
				continue;
			}
			auto it = lower_bound(occ[zero].begin(), occ[zero].end(), r);
			if (it == occ[zero].begin()) {
				cout << "NO\n";
				continue;
			}
			--it;
			auto it2 = lower_bound(occ[pre[r]].begin(), occ[pre[r]].end(), *it);
			if (it2 == occ[pre[r]].begin() || *(--it2) < l) cout << "NO\n";
			else cout << "YES\n";


		}
	}
	return 0;
}
