/*
 * 2 3 3 4 5 6
 * x = 4
 * 2 3, 3 4, 5, 6
 * 
 * 2 2, 3, 3, 5
 */
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, x; cin >> n >> x;
		vector<int> a(n);
		for (int &x : a) cin >> x;

		sort(a.rbegin(), a.rend());

		int sz = 0;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			sz++;
			if (1ll * a[i] * sz >= x) {
				sz = 0;
				ans++;
			} 
		}
		cout << ans << '\n';

	}
}
