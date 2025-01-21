#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		ll ans = 4 * m;
		int x, y; cin >> x >> y;
		for (int i = 0; i < n - 1; i++) {
			int x, y; cin >> x >> y;
			ans += 2 * x + 2 * y;
		}
		cout << ans << '\n';
	}
}
