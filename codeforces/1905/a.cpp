#include <bits/stdc++.h>
using namespace std;

#define MAXN 101

int t, n, m;

void solve() {
	cin >> n >> m;
	cout << max(n, m) << '\n';
}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}