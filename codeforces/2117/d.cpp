// 1 2 3 4 5
// 5 4 3 2 1
//
// transform array into (x, 2x, 3x, n * x) or (n * x, ..., 2x, x)
// x + n * y = a_1
// 2x + (n - 1) * y = a_2
// 3x + (n - 2) * y = a_3
// just check these values and see if there exists some x, y between them?
//
// x + n * y = a_1
// a_1 + x - y = a_2
// a_2 + x - y = a_3
//
// we know
// a2 - a1 = x - y
// x + n * y = a_1
// diff + y = x
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int &x : a) cin >> x;

		int diff = a[1] - a[0];
		bool works = true;

		for (int i = 1; i < n; i++) {
			if (a[i] - a[i - 1] != diff) {
				works = false;
				break;
			}
		}

		if (!works) {
			cout << "NO\n";
			continue;
		}

		// x - y = diff
		// x + n * y = a[0]
		// x = diff + y
		// (diff + y) + n * y = a[0]
		// (n + 1) * y + diff = a[0]
		// y = (a[0] - diff) / (n + 1)
		if ((a[0] - diff) % (n + 1) != 0) {
			cout << "NO\n";
		} else {
			int y = (a[0] - diff) / (n + 1);
			cout << ((diff + y < 0 || y < 0) ? "NO" : "YES") << '\n';
		}
	}
}
		


