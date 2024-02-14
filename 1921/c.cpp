#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

#define ll long long

ll t, n, f, a, b, m[MAXN]; 


void solve() {

	cin >> n >> f >> a >> b;
	m[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> m[i];
	}

	ll charge = f;

	for (int i = 1; i <= n; i++) {
		ll dist = m[i] - m[i - 1];
		charge -= min(dist * a, b);
	}

	if (charge > 0) cout << "YES\n";
	else cout << "NO\n";


}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}