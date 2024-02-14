#include <bits/stdc++.h>
using namespace std;

int t, n, k;

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			cout << (char) ('a' + j);
		}
	}
	cout << endl;

}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}