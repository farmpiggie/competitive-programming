#include <bits/stdc++.h>
using namespace std;

#define ll long long

int t, n;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		bool remainder_1 = false;
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			sum += x;
			if (x % 3 == 1) remainder_1 = true;
		}

		if (sum % 3 == 0) cout << "0\n";
		else if (sum % 3 == 2) cout << "1\n";
		else {
			if (remainder_1) cout << "1\n";
			else cout << "2\n";
		}
	}

	return 0;
}