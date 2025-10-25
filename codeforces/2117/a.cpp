#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, x; cin >> n >> x;
		int start = -1, end = -1;
		for (int i = 0; i < n; i++) {
			int d; cin >> d;
			if (d == 1) {
				if (start == -1) start = i;
				end = i;
			}
		}
		cout << (end - start < x ? "YES" : "NO") << '\n';
	}
}