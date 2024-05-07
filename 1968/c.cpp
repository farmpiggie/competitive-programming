// a_(i - 1) must be > x_i
// so make sure that every a_i > x_i + 1
// choose smallest a_i s.t. a_i % a_(i - 1) = x_(i - 1), but a_i > x_i
// a_0 = x_0 + 1
// a_(n - 1) % a_(n - 2) = x_(n - 2)
// 3, 5, 4, 1

#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> x(n - 1);
		for (int& a : x) cin >> a;
		vector<int> a(n);
		a[0] = x[0] + 1;
		for (int i = 1; i < n - 1; i++) {
			a[i] = x[i - 1];
			if (a[i] <= x[i]) {
				a[i] += ((x[i] - a[i]) / a[i - 1] + 1) * a[i - 1];
			}
		}
		a[n - 1] = x[n - 2];

		for (auto& num : a) cout << num << ' ';
		cout << '\n';
	}
	return 0;
}
