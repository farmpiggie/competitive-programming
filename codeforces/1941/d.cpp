#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);	
	int t; cin >> t;
	while (t--) {
		int n, m, x; cin >> n >> m >> x;
		set<int> s;
		s.insert(--x);
		for (int i = 0; i < m; i++) {
			set<int> ns;	
			int r; char c; cin >> r >> c;
			if (c == '0') {
				for (int num : s) ns.insert((num + r) % n);
			} else if (c == '1') {
				for (int num : s) ns.insert((num + n - r) % n);
			} else {
				for (int num : s) {
					ns.insert((num + r) % n);
					ns.insert((num + n - r) % n);
				}
			}
			s = ns;
		}
		cout << (int) s.size() << '\n';
		for (int num : s) cout << num + 1 << ' ';
		cout << '\n';
	}
}
