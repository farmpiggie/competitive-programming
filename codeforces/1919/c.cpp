#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

int t, n, a[MAXN];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> b, c;
	b.push_back(INT_MAX);
	c.push_back(INT_MAX);
	for (int i = 0; i < n; i++) {
		int x = b.back(), y = c.back();
		if (x > y) swap(b, c);
		x = b.back(), y = c.back();
		if (a[i] <= x || y < a[i]) {
			b.push_back(a[i]);
		} else if (x < a[i] <= y) {
			c.push_back(a[i]);
		}
	}


	int ans = 0;
	for (int i = 1; i < (int) b.size(); i++) {
		if (b[i - 1] < b[i]) ans++;
	}
	for (int i = 1; i < (int) c.size(); i++) {
		if (c[i - 1] < c[i]) ans++;
	}
	cout << ans << '\n';
}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}