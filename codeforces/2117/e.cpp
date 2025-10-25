/*
 2 1 5 3 4
 3 2 4 5 6
 */


#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		// split #s in even and odd groups
		vector<vector<int>> a(2, vector<int>(n, 0));
		for (int j = 0; j < 2; j++) {
			for (int &x : a[j]) cin >> x;
		}
		map<int, vector<int>> evens, odds;
		set<int> unique;
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < 2; i++) {
				if ((i + j) % 2 == 0) {
					evens[a[i][j]].push_back(j);
				} else {
					odds[a[i][j]].push_back(j);
				}
				unique.insert(a[i][j]);
			}
		}

		int ans = 0;

		for (int x : unique) {
			// try without removal
			if (evens.find(x) != evens.end()) {
				int end = evens[x].back();
				if (evens[x].size() >= 2 && end - evens[x][evens[x].size() - 2] > 1) {
					ans = max(ans, evens[x][evens[x].size() - 2] + 1);
				} else if (evens[x].size() >= 3) {
					ans = max(ans, evens[x][evens[x].size() - 3] + 1);
				}
			}
			if (odds.find(x) != odds.end()) {
				int end = odds[x].back();
				if (odds[x].size() >= 2 && end - odds[x][odds[x].size() - 2] > 1) {
					ans = max(ans, odds[x][odds[x].size() - 2] + 1);
				} else if (odds[x].size() >= 3) {
					ans = max(ans, odds[x][odds[x].size() - 3] + 1);
				}
			}
			if (evens.find(x) != evens.end() && odds.find(x) != odds.end()) {
				ans = max(ans, min(odds[x].back(), evens[x].back()) + 1);
			}
		}

		cout << ans << '\n';
	}
}