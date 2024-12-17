#include <bits/stdc++.h>
using namespace std;

int t, a, b;

void solve() {
	cin >> a >> b;
	if ((a + b) % 2 == 0) cout << "Bob\n";
	else cout << "Alice\n";
}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}