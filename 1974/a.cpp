#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int x, y; cin >> x >> y;
		if (y % 2 == 1) x = max(0, x - 11);
		x = max(0, x - 7 * (y / 2));
		cout << (y + 1) / 2 + (x + 14) / 15 << '\n';
	}
	return 0;
}
