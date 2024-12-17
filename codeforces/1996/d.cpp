#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	int t; cin >> t;

	while (t--) {
		ll ans = 0;
		int n, x; cin >> n >> x;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j * i <= n; j++) {
				ans += max(0, min(x - i - j, (n - i * j) / (i + j)));
			}
		}
		cout << ans << '\n';
	}
}
