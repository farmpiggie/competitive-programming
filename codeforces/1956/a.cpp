// 250 * 100 * a^2

#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int k, q; cin >> k >> q;
		vector<int> a(k);
		for (int& x : a) cin >> x;
		for (int i = 0; i < q; i++) {
			int n; cin >> n;
			if (n < a[0]) cout << n << ' ';
			else cout << (a[0] - 1) << ' ';
		}
		cout << '\n';
	}
}
