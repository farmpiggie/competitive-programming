#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int l, r; cin >> l >> r;
		vector<int> ans(r - l + 1, 0);
		iota(ans.begin(), ans.end(), 0);
		ll sum = 1ll * r * (r + 1);
		int sz = r; 
		while (sz > 0) {
			int msb = 31 - __builtin_clz(sz);
			int val = (1 << msb);
			for (int i = sz; i >= val; i--) {
				swap(ans[i], ans[i - 1 - 2 * (i - val)]);
			}
			sz -= 2 * (sz - val + 1);
		}
		cout << sum << '\n';
		for (int x : ans) cout << x << ' ';
		cout << '\n';
	}
}
	


			


