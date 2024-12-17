#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	ll a, b, n; cin >> a >> b >> n;
	ll ans = 0;
	ll time = b;
	for (int i = 0; i < n; i++) {
		ll tool; cin >> tool;
		ans += (time - 1);
		time = min(a, 1 + tool);
	}
	ans += time;
	cout << ans << endl;
}

int main() {
	int t; cin >> t;
	while (t--) solve();
}