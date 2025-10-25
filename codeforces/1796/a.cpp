#include <bits/stdc++.h>
using namespace std;

// 3 5 6 9 10 12 15, repeats every 8 values

string master = "FBFFBFFBFBFFBFFBFBFFBFFB";
int n = master.length();

void solve() {
	int k; string s; cin >> k >> s;
	// 3 5 6 9 10 12 15 18 20 21 24 25 27 30
	for (int i = 0; i < n - k + 1; i++) {
		if (master.substr(i, k) == s) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
}

int main() {
	int t; cin >> t;
	while (t--) solve();
	return 0;
}