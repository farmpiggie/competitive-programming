#include <bits/stdc++.h>
using namespace std;

int t, n;

void solve() {
	cin >> n;
	char a; 
	bool works = false;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == '0') {
			works = true;
		}
	}
	if (works) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}