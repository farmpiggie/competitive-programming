// if only one bit, contributes MSB
// otherwise if more than one bit, contributes MSB + 1
// if only two bits and first bit is ones, consider special
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, q; cin >> n >> q;
		vector<int> a(n);
		for (int &x : a) cin >> x;
		vector<ll> psum(n + 1, 0), special(n + 1, 0);
		for (int i = 0; i < n; i++) {
			int bits = __builtin_popcount(a[i]);
			psum[i + 1] = 31 - __builtin_clz(a[i]) + (bits > 1);
			if (bits == 2 && (a[i] % 2 == 1)) { 
				special[i + 1] = 1;
			}
			psum[i + 1] += psum[i];
			special[i + 1] += special[i];
		}
		while (q--) {
			int l, r; cin >> l >> r;
			cout << psum[r] - psum[l - 1] - ((special[r] - special[l - 1] + 1) / 2) << '\n';
		}
	}
}
		


			

