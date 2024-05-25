#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<vector<char>> a(n, vector<char>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
			}
		}
		int w_x_min = n + 1, w_x_max = -1, w_y_min = n + 1, w_y_max = -1;
		int b_x_min = n + 1, b_x_max = -1, b_y_min = n + 1, b_y_max = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 'B') {
					b_x_min = min(b_x_min, i);
					b_x_max = max(b_x_max, i);
					b_y_min = min(b_y_min, j);
					b_y_max = max(b_y_max, j);
				} else {
					w_x_min = min(w_x_min, i);
					w_x_max = max(w_x_max, i);
					w_y_min = min(w_y_min, j);
					w_y_max = max(w_y_max, j);
				}
			}
		}
		if ((b_x_min == 0 && b_x_max == n - 1 && b_y_min == 0 && b_y_max == m - 1) || 
			(w_x_min == 0 && w_x_max == n - 1 && w_y_min == 0 && w_y_max == m - 1)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
