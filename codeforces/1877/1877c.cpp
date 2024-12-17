#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long n, m, k;
	cin >> n >> m >> k;

	if (k > 3) {
		cout << 0 << '\n';
		return;
	}

	if (k == 1) {
		cout << 1 << endl;
		return;
	}

	if (k == 2) {
		long long ans = 0;
		ans += (min(m, (n - 1)) + (m / n));
		cout << ans << endl;
	}

	if (k == 3) {
		cout << max((long long) 0, m - (m / n) - (n - 1)) << endl;
	}


}

int main() {
	int t; cin >> t;
	while (t--) solve();
	return 0;
}