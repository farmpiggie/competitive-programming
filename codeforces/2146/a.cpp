#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		map<int, int> mp;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			mp[x]++;
		}
		vector<int> occ;
		for (auto [x, y] : mp) occ.push_back(y);
		sort(occ.rbegin(), occ.rend());

		int ans = 0;
		for (int i = 0; i < occ.size(); i++) {
			ans = max(ans, (i + 1) * occ[i]);
		}

		cout << ans << '\n';
	}
}
