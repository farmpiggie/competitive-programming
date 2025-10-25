#include <bits/stdc++.h>
using namespace std;

int t, n;
string s, temp;

// write string n with < n cases(?)

void solve() {
	cin >> n >> s;
	map<string, int> occ; // strings of length 2
	for (int i = 0; i < n - 1; i++) {
		temp = s.substr(i, 2);
		if (!occ.count(temp)) {
			occ[temp] = i;
		} else if (i - occ[temp] >= 2) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
	return;
}

int main() {
	cin >> t;
	while (t--) solve();

	return 0;
}