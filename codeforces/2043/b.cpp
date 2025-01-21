#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, d; cin >> n >> d;
		set<int> s;
		s.insert(1);
		if (d % 3 == 0 || n >= 3) s.insert(3);
		if (d == 5) s.insert(5);
		if (d == 7 || n >= 3) s.insert(7);
		if (d == 9 || n >= 6 || (d % 3 == 0 && n >= 3)) s.insert(9);
		for (int x : s) cout << x << " ";
		cout << '\n';
	}
	return 0;
}
