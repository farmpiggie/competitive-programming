#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 100005

int t, n, q;
ll k, a[MAXN], b[MAXN];

void solve() {
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}


	for (int t = 0; t < q; t++) {
		for (int i = 0; i < n; i++) {
			b[i] = a[i];
		}
		cin >> k;
		for (int i = 59; i >= 0; i--) {
			ll cost = 0;
			vector<ll> delta(n, 0);
			bool works = true;
			for (int j = 0; j < n; j++) {
				ll bit = (b[j] >> i) & 1;
				if (!bit) {
					ll digits = ((1ll << i) - 1) & b[j]; // last ith digits isolated
					ll diff = (1ll << i) - digits; // cost to flip ith bit to 1
					delta[j] = diff;
					cost += diff;
					if (cost > k) {
						works = false;
					}
				}
			}
			if (works && cost <= k) {
				k -= cost;
				for (int j = 0; j < n; j++) {
					b[j] += delta[j];
				}
			}
		}
		ll ans = b[0];
		for (int i = 0; i < n; i++) {
			ans &= b[i];
		}
		cout << ans << '\n';
	}
		
}

int main() {
	solve();
	return 0;
}