#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m, k;	

	cin >> n >> m >> k;

	vector<vector<char>> a(n, vector<char>(m, 0));


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	vector<vector<int>> rows(n, vector<int>(m, 0));
	vector<vector<int>> cols(n, vector<int>(m, 0));
	vector<vector<int>> diag1(n, vector<int>(m, 0));
	vector<vector<int>> diag2(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		rows[i][0] = (a[i][0] == '#');
		for (int j = 1; j < m; j++) {
			rows[i][j] = rows[i][j - 1] + (a[i][j] == '#');
		}
	}

	for (int j = 0; j < m; j++) {
		cols[0][j] = (a[0][j] == '#');
		for (int i = 1; i < n; i++) {
			cols[i][j] = cols[i - 1][j] + (a[i][j] == '#');
		}
	}

	for (int j = m - 1; j >= 0; j--) {
		// start is (0, j)
		diag1[0][j] = (a[0][j] == '#');
		int cur_i = 1, cur_j = j + 1;
		while (cur_i < n && cur_j < m) {
			diag1[cur_i][cur_j] = diag1[cur_i - 1][cur_j - 1] + (a[cur_i][cur_j] == '#');
			cur_i++;
			cur_j++;
		}
	}

	for (int i = 1; i < n; i++) {
		// start is (i, 0)
		diag1[i][0] = (a[i][0] == '#');
		int cur_i = i + 1, cur_j = 1;
		while (cur_i < n && cur_j < m) {
			diag1[cur_i][cur_j] = diag1[cur_i - 1][cur_j - 1] + (a[cur_i][cur_j] == '#');
			cur_i++;
			cur_j++;
		}
	}

	for (int j = 0; j < m; j++) {
		// start is (0, j)
		diag2[0][j] = (a[0][j] == '#');
		int cur_i = 1, cur_j = j - 1;
		while (cur_i < n && cur_j >= 0) {
			diag2[cur_i][cur_j] = diag2[cur_i - 1][cur_j + 1] + (a[cur_i][cur_j] == '#');
			cur_i++;
			cur_j--;
		}
	}

	for (int i = 1; i < n; i++) {
		// start is (i, 0)
		diag2[i][m - 1] = (a[i][m - 1] == '#');
		int cur_i = i + 1, cur_j = m - 2;
		while (cur_i < n && cur_j >= 0) {
			diag2[cur_i][cur_j] = diag2[cur_i - 1][cur_j + 1] + (a[cur_i][cur_j] == '#');
			cur_i++;
			cur_j--;
		}
	}

	vector<vector<int>> ans(n, vector<int>(m, 0));

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < m; j++) {
			if (i == n - 1 && j == 0) {
				for (int y = j; y - j <= k && y < m; y++) {
					for (int x = i; i - x <= k && x >= 0; x--) {
						ans[i][j] += (a[x][y] == '#');
					}
				}
			} else if (j > 0) {
				ans[i][j] = ans[i][j - 1];
				ans[i][j] -= (cols[i][j] - (i - k >= 0) ? cols[i - k][j] : 0);

				int delta_i = (j + k > m) ? (j + k - (m - 1)) : 0;
				int delta_j = (i - k < 0) ? (i - k) : 0;

				ans[i][j] += cols[i - delta_i][j + k - delta_i];

			}
		}
	}




}

int main() {
	int t; cin >> t;
	while (t--) solve();
	return 0;
}