#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
s_i + s_1 >= i, so
s_i - i >= -s_1
*/
const int N = 2e5 + 5;
int t, n, c; ll p[N], a[N];

void solve() {
	int n, c; cin >> n >> c;

	for (int i = 1; i <= n; i++)
		cin >> p[i];


	for (int i = 1; i <= n; i++)
		a[i] = i;

	// sort by i * c - s[i]
	sort(a + 1, a + n + 1, [&] (const int& u, const int& v) {
		return 1ll * u * c - p[u] < 1ll * v * c - p[v];
	});


	ll sz = p[1];
	for (int i = 1, u; i <= n; i++) {
		u = a[i];
		if (u == 1) continue;
		if (1ll * u * c > sz + p[u]) return cout << "No\n", void();
		sz += p[u];
	}
	return cout << "Yes\n", void();
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) solve();
	return 0;
}