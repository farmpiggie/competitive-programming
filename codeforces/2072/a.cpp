#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, k, p; cin >> n >> k >> p;
		k = abs(k);
		if (k == 0) {
			cout << "0\n";
		} else if (n * p < k) {
			cout << "-1\n";
		} else {
			cout << ((k - 1) / p) + 1 << '\n';
		}
	}
}

