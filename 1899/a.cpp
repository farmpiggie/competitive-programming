#include <bits/stdc++.h>
using namespace std;

int t, n;

void solve() {
	cin >> n;
	if (n % 3 == 0) cout << "Second\n";
	else cout << "First\n";
}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}