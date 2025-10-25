#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define MAXN 1005

ll t, n, a[MAXN], b[MAXN];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	for (int i = 0; i < n; i++) {
		bool works = false;
		ll max_a = a[i];
		ll min_b = b[i];
		// cout << "trying: " << a[i] << '\n';
		if (a[i] == b[i]) continue;

		for (int j = i - 1; j >= 0; j--) {
			if (a[j] == b[i]) { // match target
				if (max_a <= a[j] && min_b >= a[j]) {
					works = true;
				} 
				break;
			} else {
				max_a = max(max_a, a[j]);
				min_b = min(min_b, b[j]);
			}
		}
		max_a = a[i];
		min_b = b[i];
		for (int j = i + 1; j < n; j++) {
			if (a[j] == b[i]) { // match target
				if (max_a <= a[j] && min_b >= a[j]) {
					works = true;
				} 
				break;
			} else {
				max_a = max(max_a, a[j]);
				min_b = min(min_b, b[j]);
			}
		}
		if (!works) return cout << "No\n", void();
		// cout << "works!" << '\n';
	}
	return cout << "Yes\n", void();
}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}