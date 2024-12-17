#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<int> a(n + m + 1), b(n + m + 1);
		for (int& x : a) cin >> x;
		for (int& x : b) cin >> x;
		int special = -1;
		int p_count = 0, t_count = 0;
		ll ans = 0;
		for (int i = 0; i < n + m + 1; i++) {
			if (a[i] > b[i]) {
				p_count++;
				ans += a[i];
			} else {
				t_count++;
				ans += b[i];
			}

			if (p_count == n + 1) {
				ans -= a[i];
				special = i;
				break;
			} else if (t_count == m + 1) {
				ans -= b[i];
				special = i;
				break;
			}
		}
		for (int i = special; i < n + m + 1; i++) {
			if (a[special] > b[special]) {
				ans += b[i];
			} else {
				ans += a[i];
			}
		}
		int special2 = -1;
		for (int i = special; i < n + m + 1; i++) {
			if (a[special] > b[special] && a[i] > b[i]) {
				special2 = i;
				break;
			} else if (a[special] < b[special] && a[i] < b[i]) {
				special2 = i;
				break;
			}
		}

		for (int i = 0; i < n + m + 1; i++) {
			ll cur = ans;
			if (i < special) {
				if (a[special] > b[special] && a[i] > b[i]) { // matches
					cur -= a[i];
					cur -= b[special2];
					cur += a[special2];
				} else if (a[special] < b[special] && a[i] < b[i]) {
					cur -= b[i];
					cur -= a[special2];
					cur += b[special2];
				} else if (a[i] > b[i]) {
					cur -= a[i];
				} else {
					cur -= b[i];
				}
			} else {
				if (a[special] > b[special]) cur -= b[i];
				else cur -= a[i];
			}
			cout << cur << ' ';
		}
		cout << '\n';
				

	}
	return 0;
}
