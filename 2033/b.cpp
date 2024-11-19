#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define v2i vector<vi>

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		v2i a(n, vi(n));
		for (vi& x : a) for (int& y : x) cin >> y;
		
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int x = 0, y = i; // start at row 0, column i
			int mn = 0;
			while (x < n && y < n) {
				mn = min(mn, a[x][y]);
				x++; y++;
			}
			ans += -mn;
			if (i == 0) continue;
			x = i, y = 0; // row i, column 0
			mn = 0;
			while (x < n && y < n) {
				mn = min(mn, a[x][y]);
				x++; y++;
			}
			ans += -mn;
		}
		cout << ans << '\n';
	}
	return 0;
}
