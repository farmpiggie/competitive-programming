// optimally, each player wants to stay at their current position if it makes them the most points
// we can count the # of points that both players could make, and then compare
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, k, b, s; cin >> n >> k >> b >> s;
		b--; s--;
		vector<int> p(n), a(n);
		for (int& x : p) {
			cin >> x; --x;
		}
		for (int& x : a) cin >> x;

		ll b_best = 0, s_best = 0;
		ll b_sum = 0, s_sum = 0;
		for (int i = 0; i < min(n, k); i++) {
			// curr = sum + (k - i) * a[current pos];
			ll b_curr = b_sum + 1ll * (k - i) * a[b];	
			ll s_curr = s_sum + 1ll * (k - i) * a[s];
			b_best = max(b_best, b_curr);
			s_best = max(s_best, s_curr);
			b_sum += a[b];
			s_sum += a[s];
			b = p[b];
			s = p[s];
		}

		if (b_best > s_best) cout << "Bodya\n";
		else if (s_best > b_best) cout << "Sasha\n";
		else cout << "Draw\n";
	}
	return 0;
}
