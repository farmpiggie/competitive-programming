// anchor values of b and gcd(a, b), find all values of a?
// a = c * (x * gcd(a, b) * gcd(a, b)) - x * gcd(a, b))
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;

	while (t--) {
		int n, m; cin >> n >> m;
		ll ans = 0;
		for (ll b = 1; b <= m; b++) {
			ans += (n + b) / (b * b);
		}
		cout << ans - 1 << '\n';
	}
	return 0;
}
