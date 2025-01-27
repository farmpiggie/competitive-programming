#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		
		// move to n - 1
		bool works = true;

		for (int i = 0; i < n; i++) {
			int l = 2 * i;
			int r = 2 * (n - 1 - i);
			if (a[i] <= l || a[i] <= r) {
				works = false;
				break;
			}
		}

		cout << (works ? "YES" : "NO") << '\n';
	}
}

