#include <bits/stdc++.h>
using namespace std;

const int N = 25;
int t, n, a[N], diff[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i < n; i++)
		diff[i] = a[i + 1] - a[i];

	for (int i = 1; i < n; i++) {
		if (__builtin_popcount(i) != 1 && diff[i] < 0) return cout << "No\n", void();
	}
	return cout << "Yes\n", void();
}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}