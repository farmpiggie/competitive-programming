#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const int MAXN = 2e3 + 5;

ll t, n, k, a[MAXN];

void solve() {
	cin >> n >> k;
	ll cur_min = -1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (cur_min == -1) cur_min = a[i];
		else cur_min = min(cur_min, a[i]);
	}
	sort(a, a + n);
	if (k >= 3) return cout << "0\n", void();
	else if (k == 1) {
		for (int i = 1; i < n; i++) {
			cur_min = min(cur_min, abs(a[i] - a[i - 1]));
		}
		return cout << cur_min << '\n', void();
	} else { // k = 2
		set<ll> diffs;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				diffs.insert(abs(a[i] - a[j]));
			}
		}

		for (int i = 0; i < n; i++) {
			auto it = diffs.lower_bound(a[i]);
			if (it != diffs.end()) {
				cur_min = min(cur_min, abs(a[i] - *it));
			}
			if (it != diffs.begin()) {
				--it;
				cur_min = min(cur_min, abs(a[i] - *it));
			}
		}
		cur_min = min(cur_min, *diffs.begin());
		cout << cur_min << '\n';
	}




}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}