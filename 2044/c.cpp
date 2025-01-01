#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int m, a, b, c; cin >> m >> a >> b >> c;
		int filled = min(m, a) + min(m, b);
		filled = min(filled + c, 2 * m);
		cout << filled << '\n';
	}
	return 0;
}
