#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll t, x, n;

void solve() {
	cin >> x >> n;
	int ans = 0;
	for (int i = 1; i <= (int) sqrt(x); i++) {
		if (x % i == 0 && x / i >= n) {
			ans = max(ans, i);
		}
		if (x % i == 0) {
			int j = x / i;
			if (x % j == 0 && x / j >= n) {
				ans = max(ans, j);
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	cin >> t;
	while (t--) solve();
}