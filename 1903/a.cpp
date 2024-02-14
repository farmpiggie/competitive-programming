#include <bits/stdc++.h>
using namespace std;

#define MAXN 105

int t, n, k, a[MAXN];

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	if (k >= 2) return cout << "YES\n", void();

	for (int i = 1; i < n; i++) {
		if (a[i - 1] > a[i]) {
			return cout << "NO\n", void();
		}
	}

	cout << "YES\n", void();

}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}