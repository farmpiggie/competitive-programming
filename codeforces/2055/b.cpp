#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n), b(n);
		for (int& x : a) cin >> x;
		for (int& x : b) cin >> x;
		
		int increase = 0;
		vector<int> rem(n);
		for (int i = 0; i < n; i++) {
			rem[i] = b[i] - a[i];
			if (rem[i] > 0) increase++; // increase required
		}

		if (increase > 1) {
			cout << "NO\n";
			continue;
		} else if (increase == 0) {
			cout << "YES\n";
			continue;
		}
		
		// increase == 1
		sort(rem.begin(), rem.end());
		if (abs(rem[n - 2]) < rem[n - 1]) {
			cout << "NO\n";
		} else cout << "YES\n";	

			
	}
	return 0;
}

			
		
