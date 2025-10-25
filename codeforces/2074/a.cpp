#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int l, r, d, u; cin >> l >> r >> d >> u;
		cout << ((l == r && r == d && d == u) ? "YES" : "NO") << '\n';
	}
}