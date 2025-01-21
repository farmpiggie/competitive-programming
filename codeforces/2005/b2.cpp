#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m, q; cin >> n >> m >> q;
		vector<int> b(m);
		for (int& x : b) cin >> x;
		sort(b.begin(), b.end());
		while (q--) {
			int x; cin >> x;
			if (x < b[0]) cout << b[0] - 1 << '\n';
			else if (x > b[m - 1]) cout << n - b[m - 1] << '\n';
			else {
				int idx = lower_bound(b.begin(), b.end(), x) - b.begin();
				int l = b[idx - 1], r = b[idx];
				int a = x - l, b = r - x;
				cout << min(a, b) + abs(a - b) / 2 << '\n';
			}
		}
	}
	return 0;
}
