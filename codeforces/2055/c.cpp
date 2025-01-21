#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		string direction; cin >> direction; // n + m - 1 length
		vector<vector<ll>> grid(n, vector<ll>(m, 0));
		for (auto& x : grid) {
			for (ll& y : x) {
				cin >> y;
			}
		}
		vector<ll> row(n, 0);
		vector<ll> col(m, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				row[i] += grid[i][j];
			}
		}

		for (int j = 0; j < m; j++) {
			for (int i = 0; i < n; i++) {
				col[j] += grid[i][j];
			}
		}
		
		int x = 0, y = 0;	
		for (char c : direction) {
			if (c == 'D') { // evaluate at row
				grid[x][y] = -row[x];
				row[x] += grid[x][y];
				col[y] += grid[x][y];
				x++;
			} else {
				grid[x][y] = -col[y];
				row[x] += grid[x][y];
				col[y] += grid[x][y];
				y++;
			}
		}
		grid[n - 1][m - 1] = -row[n - 1];

		for (auto& x : grid) {
			for (ll y : x) {
				cout << y << " ";
			}
			cout << '\n';
		}			
	}
	return 0;
}	




			
