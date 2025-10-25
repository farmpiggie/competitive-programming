#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; string s;
	cin >> n >> s;
	int unique = 1;
	for (int i = 1; i < n - 1; i++) {
		if (s[i - 1] != s[i + 1]) unique++;
	}
	cout << unique << endl;
}

int main() {
	int t; cin >> t;
	while (t--) solve();
	return 0;
}