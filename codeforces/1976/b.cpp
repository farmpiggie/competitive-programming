#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n), b(n + 1);
		for (int& x : a) cin >> x;
		for (int& x : b) cin >> x;
		
		int best = (int) 1e9;


		ll ans = 0;
		for (int i = 0; i < n; i++) {
			if ((a[i] <= b[n] && b[n] <= b[i]) || (b[i] <= b[n] && b[n] <= a[i])) {
				best = 0;
			} else {
				best = min(best, min(abs(b[i] - b[n]), abs(a[i] - b[n])));
			}
			ans += abs(a[i] - b[i]);
		}
		cout << ans + 1 + best << '\n';
	}
}
