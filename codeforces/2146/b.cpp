#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<int> cnt(m + 1, 0);
		vector<vector<int>> sets;
		for (int i = 0; i < n; i++) {
			int l; cin >> l;
			vector<int> cur;
			for (int j = 0; j < l; j++) {
				int x; cin >> x;
				cur.push_back(x);
				cnt[x]++;
			}
			sets.push_back(cur);
		}

		bool feasible = true;
		for (int i = 1; i <= m; i++) {
			if (cnt[i] == 0) {
				feasible = false;
				break;
			}
		}

		if (!feasible) {
			cout << "NO\n";
			continue;
		}

		int possible = 0;
		for (vector<int>& set : sets) {
			bool works = true;
			for (int x : set) if (cnt[x] == 1) {
				works = false;
				break;
			}
			if (works) possible++;
		}

		cout << (possible >= 2 ? "YES" : "NO") << '\n';
	}
}

