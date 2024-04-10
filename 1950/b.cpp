#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 0; i < 2 * n; i++) {
			for (int j = 0; j < 2 * n; j++) {
				if ((i / 2) % 2 == 0) {
					if ((j / 2) % 2 == 0) {
						cout << "#";
					} else {
						cout << ".";
					}
				} else {
					if ((j / 2) % 2 == 0) {
						cout << ".";
					} else {
						cout << "#";
					}
				}
			}
			cout << '\n';
		}
	}
	return 0;
}
