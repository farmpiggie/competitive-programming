/*
 * swapping b_i and b_j results in a change of (|a_i - b_j| + |a_j - b_i|) - (|a_i - b_i| + |a_j - b_j|)
 * what if we anchor some b_i to swap, and choose the best b_j to swap it with!
 * makes sense that we'd like to match b_i with some value a_x where |a_x - b_i| is greater
 *
 * we want: |a_i - b_i| + |a_j - b_j| < |a_j - b_i| + |a_i - b_j|
 *
 * let us define diff(i) = a_i - b_i
 *
 * if a_j > b_i and a_i > b_j:
 * 	diff(i) + diff(j) < diff(i) + diff(j) <-- never true, no need to switch.
 *
 * if a_j < b_i and a_i < b_j:
 * 	diff(i) + diff(j) < b_i - a_j + b_j - a_i
 * 	diff(i) + diff(j) < -diff(i) + -diff(j)
 * 	2 * (diff(i) + diff(j)) < 0
 *
 * if a_j > b_i and a_i < b_j
 * 	diff(i) + diff(j) < a_j - b_i + b_j - a_i
 * 	diff(i) + diff(j) < -sum(i) + sum(j)
 * 	diff(i) + sum(i) + diff(j) - sum(j) < 0
 * 	2 * a_i - 2 * b_j < 0
 * 	a_i < b_j
 *
 * if a_j < b_i and a_i > b_j
 * 	diff(i) + diff(j) < b_i - a_j + a_i - b_j
 * 			  < sum(i) - sum(j)
 * 	a_j < b_i
 * 	b_i > a_j
 *	
 * for a given i, we can find the smallest a_j, largest b_j, or smallest diff(j). try swapping all these three.
 *
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<ll, ll>
int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<ll> a(n), b(n);
		for (ll& x : a) cin >> x;
		for (ll& x : b) cin >> x;
		vector<ll> diff(n);
		for (int i = 0; i < n; i++) diff[i] = abs(a[i] - b[i]);

		vector<pii> w, x, y, z;
		for (int i = 0; i < n; i++) {
			w.push_back({a[i] - b[i] - diff[i], i});
			x.push_back({b[i] - a[i] - diff[i], i});
			y.push_back({-a[i] - b[i] - diff[i], i});
			z.push_back({a[i] + b[i] - diff[i], i});
		}
		sort(w.begin(), w.end());
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		sort(z.begin(), z.end());

		ll reg = 0;
		for (int i = 0; i < n; i++) reg += abs(diff[i]);

//		cout << "reg: " << reg << '\n';
		auto delta = [&](int i, int j) {
			return abs(a[i] - b[j]) + abs(a[j] - b[i]) - abs(a[i] - b[i]) - abs(a[j] - b[j]);
		};

		ll ans = reg;
		for (int i = 0; i < n; i++) {
			int j = (w[n - 1].second == i ? w[n - 2].second : w[n - 1].second); // smallest a[j]
//			cout << "trying: " << i << " " << j << '\n';
//			cout << delta(i, j) << '\n';
			ans = max(ans, reg + delta(i, j));
			j = (x[n - 1].second == i ? x[n - 2].second : x[n - 1].second);
//			cout << "trying: " << i << " " << j << '\n';
//			cout << delta(i, j) << '\n';
			ans = max(ans, reg + delta(i, j));
			j = (y[n - 1].second == i ? y[n - 2].second : y[n - 1].second);
//			cout << "trying: " << i << " " << j << '\n';
//			cout << delta(i, j) << '\n';
			ans = max(ans, reg + delta(i, j));
			j = (z[n - 1].second == i ? z[n - 2].second : z[n - 1].second);
//			cout << "trying: " << i << " " << j << '\n';
//			cout << delta(i, j) << '\n';
			ans = max(ans, reg + delta(i, j));
		}
		cout << ans << '\n';

	}	
	return 0;
}
