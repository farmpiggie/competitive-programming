#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int main() {
	// ifstream cin("doremycityconstruction.in");
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		if (a[0] == a[n - 1]) {
			cout << n / 2 << endl;
			continue;
		}
		ll ans = 0;
		for (int l = 0, r = 0; l < n; l = r = r + 1) {
			while (r + 1 < n && a[r + 1] == a[l]) r++;
			ans = max(ans, 1ll * (n - (r + 1)) * (r + 1));
		}
		cout << ans << endl;

	}
	return 0;
}