/*
 * sort intervals by endpoints.
 *
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> l(n), r(n);
		for (int i = 0; i < n; i++) {
			cin >> l[i] >> r[i]; 
		}		

		vector<int> a(n);
		iota(a.begin(), a.end(), 0);

		sort(a.begin(), a.end(), [&](int x, int y) {
				if (l[x] == l[y]) return r[x] > r[y];
				else return l[x] < l[y];
				});
	
		vector<int> ans(n, 0);	
		set<int> s;
		for (int i : a) {
			auto it = s.lower_bound(r[i]);
			if (it != s.end()) ans[i] += *it - r[i];
			s.insert(r[i]);
		}

		for (int i = 0; i < n; i++) {
			l[i] = -l[i];
			r[i] = -r[i];
			swap(l[i], r[i]);
		}

		sort(a.begin(), a.end(), [&](int x, int y) {
				if (l[x] == l[y]) return r[x] > r[y];
				else return l[x] < l[y];
				});

		s.clear();	
		for (int i : a) {
			auto it = s.lower_bound(r[i]);
			if (it != s.end()) ans[i] += *it - r[i];
			s.insert(r[i]);
		}

		map<array<int, 2>, int> cnt;
		for (int i = 0; i < n; i++) {
			cnt[{l[i], r[i]}]++;
		}

		for (int i = 0; i < n; i++) {
			if (cnt[{l[i], r[i]}] > 1) {
				ans[i] = 0;
			}
		}
		
		for (int x : ans) cout << x << '\n';
	}
}
