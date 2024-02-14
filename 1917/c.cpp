#include <bits/stdc++.h>
using namespace std;

#define MAXN 2005
#define MAXK 100005
#define ll long long

int t, n, k, d, a[MAXN], v[MAXK];

void solve() {
	cin >> n >> k >> d;

	ll init = 0;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		init += (a[i] == i);
	}

	for (int j = 0; j < k; j++) {
		cin >> v[j];
	}

	ll best = init + ((d - 1) / 2); // sell on day 1, rest of days used in cycle

	for (int j = 2; j <= min(d, 2 * n + 1); j++) { // selling on day j
		for (int i = 1; i <= v[(j - 2) % k]; i++) {
			a[i]++;
		}
		ll good = 0;
		for (int i = 1; i <= n; i++) {
			good += (a[i] == i);
		}
		best = max(best, good + (d - j) / 2);
	}

	cout << best << '\n';


}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}