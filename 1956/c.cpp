// can i maximize the number of n? at most 2* n number of n
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		ll n; cin >> n;
		vector<vector<int>> arr(n, vector<int>(n, 0));
		for (int i = n - 1; i >= 0; i--) {
			for (int row = 0; row < n; row++) {
				arr[row][i] = row + 1;
			}
			for (int col = 0; col < n; col++) {
				arr[i][col] = col + 1;
			}
		}
		ll ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				ans += arr[i][j];
		cout << ans << " " << 2 * n << '\n';
		for (int i = n - 1; i >= 0; i--) {
			cout << 1 << " " << i + 1 << " ";
			for (int j = 1; j <= n; j++) cout << j << ' ';
			cout << '\n';

			cout << 2 << " " << i + 1 << " ";
			for (int j = 1; j <= n; j++) cout << j << ' ';
			cout << '\n';
		}
	}
	return 0;
}
