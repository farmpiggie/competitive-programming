#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m, q;
		cin >> n >> m >> q;
		int l, r; cin >> l >> r;
		if (l > r) swap(l, r);

		int x; cin >> x; // position of player
		
		int a = (x - l), b = (r - x);		//
		if (x < l) cout << (l - 1) << '\n';
		else if (x > r) cout << (n - r) << '\n';
		else cout << min(a, b) + abs(a - b) / 2 << '\n';
	}
	return 0;
}

