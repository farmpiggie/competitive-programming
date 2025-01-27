#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<vector<int>> cards(n, vector<int>(m, 0));
		for (auto& x : cards) {
			for (int& y : x) {
				cin >> y;
			}
			sort(x.begin(), x.end());
		}

		bool valid = true;
		for (auto& hand : cards) {
			if (!valid) break;
			for (int i = 1; i < hand.size(); i++) {
				if (hand[i] - hand[i - 1] != n) {
					valid = false;
					break;
				}
			}
		}
		if (!valid) {
			cout << "-1\n";
		} else {
			vector<int> ans(n);
			for (int i = 0; i < n; i++) {
				ans[cards[i][0]] = i + 1;
			}
			for (int x : ans) cout << x << " ";
			cout << '\n';
		}
	}
}
		
