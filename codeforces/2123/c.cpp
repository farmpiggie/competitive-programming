/*
 * can i make both prefix and suffix around a[i] both smaller or both bigger?
 * or can i make prefix bigger, suffix smaller?
 * only not possible if prefix smaller, suffix bigger.
 *
 * 7 6 5 4 3 2 1
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		map<int, int> l, r;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (i == 0) continue;
			r[a[i]]++;
		}

		vector<int> ans(n, 1);
		for (int i = 0; i < n; i++) {
			if (l.size() > 0 && r.size() > 0 && l.begin()->first < a[i] && a[i] < r.rbegin()->first) {
				ans[i] = 0;
			}
			l[a[i]]++;
			if (i + 1 < n) {
				r[a[i + 1]]--;
				if (r[a[i + 1]] == 0) r.erase(a[i + 1]);
			}
		}
		for (int x : ans) cout << x;
		cout << '\n';
	}
}
		
		

		
