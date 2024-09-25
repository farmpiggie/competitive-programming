#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		if (n % 2 == 0) {
			cout << "-1\n";
			continue;
		}
		for (int i = 0; i < n / 2; i++) {
			cout << (i + 1) << " " << (n - i) << ' ';
		}
		cout << (n + 1) / 2 << '\n';
	}
}