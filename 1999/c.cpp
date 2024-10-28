#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, s, m; cin >> n >> s >> m;
		int prev = 0;
		bool works = false;
		for (int i = 0; i < n; i++) {
			int l, r; cin >> l >> r;
			if (l - prev >= s) works = true;
			prev = r;
		}
		works |= (m - prev >= s);
		if (works) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}