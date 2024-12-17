#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

typedef long long ll;

int t, n;
ll k, a[MAXN];

ll GCD(ll x, ll y) {
    if (y == 0) return x;
    return GCD(y, x%y);
}

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll f = a[0] - k;
	for (int i = 1; i < n; i++) {
		f = GCD(f, a[i] - k);
	}
	if (f == 0) {
		cout << "0\n";
		return;
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if ((a[i] - k) % f == 0) {
			if ((a[i] - f - k) / f < 0) {
				cout << "-1\n";
				return;
			}
			ans += (a[i] - f - k) / f;
		}
	}
	cout << ans << '\n';
}



int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}
