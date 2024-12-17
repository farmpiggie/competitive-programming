#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

// 1 4 4 3 5 7 6
// 1 4 4 3 5 3 4 6 (+1)
// 1 4 4 3 2 3 3 4 6 (+1)
// 1 4 4 1 2 3 3 4 6 (+1)
// 1 4 1 1 1 1 1 2 3 3 4 6 (+3)
// 1 1 1 1 1 1 1 1 1 1 2 3 3 4 6 (+3)

typedef long long ll;

int t, n;
ll a[MAXN];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	ll ans = 0;
	for (int i = n - 1; i > 0; i--) {
		ll k = a[i - 1] / a[i] + (a[i - 1] % a[i] != 0);
		ans += (k - 1);
		a[i - 1] = a[i - 1] / k;
	}

	cout << ans << '\n';
}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}