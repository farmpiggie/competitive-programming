#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

int t, n, m, a[MAXN], closest[MAXN], pre[MAXN], suf[MAXN];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	closest[0] = 1;
	closest[n - 1] = n - 2;
	for (int i = 1; i < n - 1; i++) {
		if (abs(a[i] - a[i - 1]) < abs(a[i] - a[i + 1])) {
			closest[i] = i - 1;
		} else {
			closest[i] = i + 1;
		}
	}
	pre[0] = 0;
	for (int i = 1; i < n; i++) {
		if (closest[i - 1] == i) {
			pre[i] = pre[i - 1] + 1;
		} else {
			pre[i] = pre[i - 1] + a[i] - a[i - 1];
		}
		// cout << pre[i] << ' ';
	}
	// cout << '\n';
	suf[n - 1] = 0;
	for (int i = n - 2; i >= 0; i--) {
		if (closest[i + 1] == i) {
			suf[i] = suf[i + 1] + 1;
		} else {
			suf[i] = suf[i + 1] + a[i + 1] - a[i];
		}
		// cout << suf[i] << ' ';
	}
	// cout << '\n'; 

	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		int ans = 0;
		if (a < b) {
			// cout << a << ' ' << b << '\n';
			ans = pre[b] - pre[a];
		} else {
			ans = suf[b] - suf[a];
		}
		cout << ans << '\n'; 
	}
}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}