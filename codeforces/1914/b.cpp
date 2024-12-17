#include <bits/stdc++.h>
using namespace std;

int t, n, k;

// 5 4 3 2 1 = 0
// 5 4 3 1 2 = 1
// 5 4 1 2 3 

void solve() {
	cin >> n >> k;
	for (int i = n; i > (k + 1); i--) {
		cout << i << ' ';
	}
	for (int i = 1; i <= (k + 1); i++) {
		cout << i << ' ';
	}
	cout << '\n';
}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}