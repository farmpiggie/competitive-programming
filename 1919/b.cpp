#include <bits/stdc++.h>
using namespace std;

int t, n;

void solve() {
	cin >> n;
	int diff = 0;
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		if (c == '+') diff++;
		else diff--;
	}
	cout << abs(diff) << '\n';
}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}