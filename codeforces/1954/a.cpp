#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, m, k; cin >> n >> m >> k;
		int max_color = (n / m) + (n % m != 0);
		if (n - max_color <= k) cout << "NO\n";
		else cout << "YES\n";
	}
}
