#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int& x : a) cin >> x;

	for (int i = 1; i < n; i++) {
		int mn = min(a[i - 1], a[i]);
		a[i - 1] -= mn;
		a[i] -= mn;	
	}

	for (int i = 1; i < n; i++) {
		if (a[i - 1] > a[i]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) solve();
}
