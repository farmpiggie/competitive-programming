#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

#define ll long long

int t, n, m, a[MAXN], b[MAXN];

void solve() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	sort(a, a + n);
	sort(b, b + m);

	int la = 0, lb = n - 1;
	int lc = 0, ld = m - 1;

	ll ans = 0;

	while (la <= lb) {
		vector<int> v(4);
		v[0] = abs(a[la] - b[lc]);
		v[1] = abs(a[la] - b[ld]);
		v[2] = abs(a[lb] - b[lc]);
		v[3] = abs(a[lb] - b[ld]);

		sort(v.begin(), v.end());

		if (v[3] == abs(a[la] - b[lc])) {
			lc++;
			la++;
		} else if (v[3] == (abs(a[la] - b[ld]))) {
			ld--;
			la++;
		} else if (v[3] == abs(a[lb] - b[lc])) {
			lb--;
			lc++;
		} else {
			lb--;
			ld--;
		}

		ans += 1ll * v[3];
	}

	cout << ans << '\n';
	


}

int main() {	
	cin >> t;
	while (t--) solve();
	return 0;
}