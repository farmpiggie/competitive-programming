#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		if (n % 2 == 0) { // even numbers
			if (m <= n && m % 2 == 0) cout << "YES\n";
			else cout << "NO\n";
		} else { // odd numbers
			if (m <= n && m % 2 == 1) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}
