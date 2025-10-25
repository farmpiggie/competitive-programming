#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int x, y; cin >> x >> y;
		if (y == 1) {
			cout << "-1\n";
		} else if (x < y) {
			cout << "2\n";
		} else if (x - 1 > y) {
			cout << "3\n";
		} else {
			cout << "-1\n";
		}
	}
}