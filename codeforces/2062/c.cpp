#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<ll> a(n);
		for (ll& x : a) cin >> x;
		
		if (n == 1) {
			cout << a[0] << '\n';
			continue;
		}

		ll ans = 0, sum = 0;
		for (ll x : a) {
			ans += x;
			sum += x;
		}

		while (a.size() > 1) {
			vector<ll> b(a.size() - 1);
			for (int i = 1; i < a.size(); i++) {
				b[i - 1] = a[i] - a[i - 1];
			}
			ans = max(ans, max(a.back() - a[0], a[0] - a.back()));
			a = b;
		}
		cout << ans << '\n';
				

	}
}	
