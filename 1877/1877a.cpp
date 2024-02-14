#include <bits/stdc++.h>
using namespace std;


void solve() {
	int total = 0;
	int n; cin >> n;
	int a;
	for (int i = 0; i < n - 1; i++) {
		cin >> a;
		total += a;
	}
	cout << -total << endl;
}

int main() {
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}