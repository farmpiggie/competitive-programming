#include <bits/stdc++.h>
using namespace std;
// -1, 3, -1, 3, -1
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		if (n == 2) {
			cout << "-1 2\n";
		} else {
			// -1 3 -1 2
			for (int i = 0; i < n; i++) {
				if (i % 2 == 0) {
					cout << "-1 ";
				} else {
					if (i == n - 1) {
						cout << "2 ";
					} else {
						cout << "3 ";
					}
				}
			}
			cout << '\n';
		}
	}
}

