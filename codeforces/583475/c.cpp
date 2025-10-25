// always choose p3...p7 consecutively
// p2 is largest j s.t. p4 + ... + p7 - p3
#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vector<int> a(n);
	for (int& x : a) cin >> x;

	sort(a.begin(), a.end());
	
	ll x = a[0] + a[1] + a[2] + a[3]; // p4 through p7
	ll ans = -1;
	
	auto find = [&](int i, int x) { return lower_bound(a.begin() + i, a.end(), x) - a.begin() - 1; };

	for (int i = 4; i <= n - 3; i++) {
		int j = find(i + 1, x - a[i]);
		int k = find(j + 1, a[i] + a[j]);
	
		auto check = [&]() {
			return i < j && j < k && k < n && x > a[i] + a[j] && a[i] + a[j] > a[k];
		};

		if (!check()) {
			--j;
			k = find(j + 1, a[i] + a[j]);
		}
		if (!check()) {
			--j;
			k = find(j + 1, a[i] + a[j]);
		}
		if (check()) ans = max(ans, x + a[i] + a[j] + a[k]);
		
		x += a[i] - a[i - 4];
	}
	cout << ans << '\n';


}
