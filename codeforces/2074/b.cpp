#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int &x : a) cin >> x;

		ll ans = 0;
		for (int &x : a) ans += x;

		cout << ans - (n - 1) << '\n';
	}
}

	