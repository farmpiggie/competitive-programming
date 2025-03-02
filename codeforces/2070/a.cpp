/*
 * count number of #s in [0, n] s.t. x % 3 == x % 5
 * obv works for 0, 15, 30, etc.
 * also works for 1, 16, 31, etc.
 * also works for 2, 17, 32, etc.
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		ll ans = 0;	
		ans += n / 15 + 1;
		if (n > 0) ans += (n - 1) / 15 + 1;
		if (n > 1) ans += (n - 2) / 15 + 1;
		cout << ans << '\n';
	}
}
