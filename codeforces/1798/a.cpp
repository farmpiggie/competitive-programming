#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	int bigx = 0, bigy = 0;
	int secondbigx, secondbigy = 0;
	// array x
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	int max_a = 0, max_b = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < b[i]) swap(a[i], b[i]);
		max_a = max(a[i], max_a);
		max_b = max(b[i], max_b);
	}
 
	if (max_a == a[n - 1] && max_b == b[n - 1]) cout << "YES" << endl;
	else cout << "NO" << endl;

}

int main() {
	int t; cin >> t;
	while (t--) solve();
	return 0;
}