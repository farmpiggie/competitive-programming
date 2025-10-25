#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}

		int cur = a[1];
		int left = 1;
		ll ans = LLONG_MAX;
		for (int i = 1; i <= n; i++) {
			if (cur != a[i]) {
				left = i;
				cur = a[i];
			}
			ans = min(ans, 1ll * a[i] * ((left - 1) + (n - i)));
		}
		cout << ans << '\n';
	}
}

