#include <bits/stdc++.h>
using namespace std;

#define ll long long

void run() {
	int n; cin >> n;
	vector<vector<int>> a(2, vector<int>(n, 0));
	vector<int> cur(n + 1, 0); 
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			char c; cin >> c;
			a[i][j] = (c - '0');
		}
	}
	for (int i = 1; i <= n; i++) {
		cur[i] = a[1][i - 1];
	}
	cur[0] = a[0][0];
	int cnt = 1;
	for (int i = 1; i < n; i++) {
		if (a[0][i] < cur[i]) { // better path found
			cnt = 1;
			cur[i] = a[0][i];
		} else if (a[0][i] == cur[i]) {
			cnt++;
		} else {
			break;
		}
	}
	for (int i = 0; i < n + 1; i++) {
		cout << cur[i];
	}
	cout << '\n';
	cout << cnt << '\n';
}	

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t; while (t--) run();
 	return 0;
}