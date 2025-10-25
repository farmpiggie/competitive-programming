#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++) {
			char c; cin >> c;
			a[i] = (c - '0');
		}
		for (int i = 0; i < n; i++) {
			char c; cin >> c;
			b[i] = (c - '0');
		}
		int odd = 0, even = 0;
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				if (a[i] == 0) even++;
				if (b[i] == 0) odd++;
			} else {
				if (b[i] == 0) even++;
				if (a[i] == 0) odd++;
			}
		}
		cout << ((even >= (n + 1) / 2 && odd >= n / 2) ? "YES" : "NO") << '\n';
	}
}
