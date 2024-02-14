#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define MAXN 100005

int t, n, q;


ll len[MAXN], lst[MAXN];


void solve() {
	cin >> n >> q;

	len[0] = 0; lst[0] = 0;

	for (int i = 1; i <= n; i++) {
		int b; cin >> b;
		if (b == 1) {
			len[i] = len[i - 1] + 1;
			cin >> lst[i];
		} else {
			ll x; cin >> x;
			if (x + 1 > 2e18 / len[i - 1]) {
				len[i] = 2e18;
			} else {
				len[i] = len[i - 1] * (x + 1);
			}
			lst[i] = lst[i - 1];
		}
	}

	for (int i = 0; i < q; i++) {
		ll k; cin >> k;
		
		while (true) {
			int cur = lower_bound(len + 1, len + n + 1, k) - len;
			if (len[cur] == k) {
				cout << lst[cur] << ' ';
				break;
			}
			if (k % len[cur - 1] == 0) {
				cout << lst[cur - 1] << ' ';
				break;
			}
			k %= len[cur - 1];
		}
	}
	cout << '\n';
}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}