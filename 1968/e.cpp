#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << "1 1\n1 2\n";
		for (int i = 3; i <= n; i++) {
			cout << i << ' ' << i << '\n';
		}
	}
	return 0;
}
