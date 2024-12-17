#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 100005

int t, n;
ll a[MAXN];
ll pre[MAXN];

void solve() {
	ll ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ans += (i + 1) * a[i];
	}
	pre[0] = a[0];
	for (int i = 1; i < n; i++) {
		pre[i] = pre[i - 1] + a[i];
	}

	for (int i = 0; i < n; i++) {
		ll val = pre[n - 1] - pre[i];
		if (val < 0) ans += -val;
	}
	cout << ans << '\n';
}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}