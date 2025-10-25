#include <bits/stdc++.h>
using namespace std;

int t, n, ans;

// 42: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 40
void solve() {
	cin >> n;
	ans = 0;
	if (n <= 10) {
		cout << n << endl;
		return;
	} else {
		// 100, we do 20-90
		while (n >= 10) {
			ans += 9;
			n /= 10;
		}
		ans += n;
		cout << ans << endl;
		return;
	}
}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}