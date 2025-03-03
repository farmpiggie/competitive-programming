/*
 * there are at most two sets: (i + j) % 2 is even or odd
 *
 * nvm just check if a color touches another of the same block.
 *
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> dx = {0, 1, 0, -1};
	vector<int> dy = {1, 0, -1, 0};

	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		
		vector<vector<int>> a(n, vector<int>(m, 0));

		map<int, int> mp;
		for (auto &x : a) {
			for (int &y : x) {
				cin >> y;
				mp[y] = 1;
			}
		}

		auto in_range = [&](int x, int y) {
			return (x >= 0 && x < n && y >= 0 && y < m); 
		};


		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < 4; k++) {
					int ni = i + dx[k], nj = j + dy[k];
					if (in_range(ni, nj) && a[ni][nj] == a[i][j]) {
						mp[a[i][j]] = 2;
					}
				}
			}
		}

		int ans = 0;
		int mx = 0;
		for (auto [_, x] : mp) {
			ans += x;
			mx = max(x, mx);
		}
		cout << ans - mx << '\n';
	}
}


