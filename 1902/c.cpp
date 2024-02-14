#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN (int) 2e5+5

ll t, n, a[MAXN];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	if (n == 1) {
		return cout << "1\n", void();
	}

	sort(a, a + n);

	ll g = abs(a[1] - a[0]);
	for (int i = 2; i < n; i++) {
		g = gcd(g, abs(a[i] - a[i - 1]));
	}

	g = max(g, (ll)1);

	// cout << "gcd: " << running_gcd << '\n';

	int j = n - 1;
	ll res = a[n - 1];
	while (true){
		while (j >= 0 && a[j] > res) {
			j--;
		}
		if (j < 0 || a[j] != res) {
			break;
		}
		res -= g;
	}

	ll sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	cout << ((a[n - 1] * (n + 1) - (sum + res))) / g << '\n';
}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}