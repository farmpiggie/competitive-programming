// not possible if sum(p1 + p2 + p3) % 2 == 1
// p1 <= p2 <= p3
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int p1, p2, p3; cin >> p1 >> p2 >> p3;
		if ((p1 + p2 + p3) % 2 != 0) {
			cout << "-1\n";
		} else {
			if (p1 + p2 >= p3) cout << (p1 + p2 + p3) / 2 << '\n';
			else cout << (p1 + p2) << '\n';
		}
	}
}
