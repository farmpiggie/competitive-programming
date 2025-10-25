#include <bits/stdc++.h>
using namespace std;

int main() {
	// ifstream cin("thermostat.in");
	int t; cin >> t;
	while (t--) {
		int l, r, x;
		cin >> l >> r >> x;
		int a, b; 
		cin >> a >> b;
		// case that |a - b| >= x
		if (abs(a - b) >= x) cout << 1 << endl;
		else if (a == b) cout << 0 << endl;
		else if (abs(l - r) < x) cout << -1 << endl;
		else if ((a + x <= r && b + x <= r) || (a - x >= l && b - x >= l)) cout << 2 << endl;
		else if ((a + x > r && a - x < l) || (b + x > r && b - x < l)) cout << -1 << endl;
		else cout << 3 << endl;
	}
	return 0;
}