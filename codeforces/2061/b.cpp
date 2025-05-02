/*
 * two sides x, top a, bottom b
 *
 * assume a <= b
 *
 * 2x + a > b
 * b - a < 2x
 *
 * find some side lengths x s.t. cnt[x] >= 2
 * find some (a,b) s.t. b - a < 2x
 *
 * choose largest x (this should be most helpful).
 *
 * sort remainding sides, choose two adjacent with smallest diff (or the same?)
 */
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

		int side = -1;
		for (auto [x, cnt] : mp) {
			if (cnt >= 2) {
				side = max(side, x);
			}
		}

		if (side == -1) {
			cout << "-1\n";
			continue;
		}

		mp[side] -= 2;
		if (mp[side] == 0) mp.erase(side);
		
		bool found = false;
		for (auto [x, cnt] : mp) {
			if (cnt >= 2) {
				cout << side << " " << side << " " << x << " " << x << '\n';
				found = true;
				break;
			}
		}

		if (found) continue;

		vector<int> a;
		for (auto [x, _] : mp) a.push_back(x);

		for (int i = 1; i < (int) a.size(); i++) {
			if (a[i] - a[i - 1] < 2 * side) {
				cout << side << " " << side << " " << a[i] << " " << a[i - 1] << '\n';
				found = true;
				break;
			}
		}

		if (!found) cout << "-1\n";
	}
}
		
		

		

