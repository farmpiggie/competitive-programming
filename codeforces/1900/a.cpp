#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	// block of size 3 or more requies (n + 1) / 2 pours of water
	// a block of size 3 or more is all the type 1s you need
	while (t--) {
		int n; cin >> n;
		int sz = 0;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			char c; cin >> c;
			if (c == '#') {
				if (sz > 0) {
					a.push_back(sz);
					sz = 0;
				} 
			} else {
				sz++;
			}
		}
		if (sz > 0) a.push_back(sz);

		// find smallest block >= 3 in length
		sort(a.begin(), a.end());
		int x = -1;
		for (int y : a) {
			if (y >= 3) {
				x = y;
				break;
			}
		}

		// if no block >= 3 in length
		int ans;
		if (x == -1) {
			ans = 0;
			for (int y : a) ans += y; // sz 1 or 2 needs all fills
		} else {
			ans = 2; // only takes two fills to make "infinite" water
		}
		cout << ans << '\n';
	}
}	



