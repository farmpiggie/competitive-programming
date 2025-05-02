/*
 * notice that after the first n terms, every two next elements in the series are equal.
 * so notice that the xth element = xor(a_1 through a_n) xor s_(x / 2) if (x / 2 - n) is odd.
 * for n = 5, s_15 = xor(a_1 through a_5) xor s_6 xor s_7
 * for n = 6, s_16 = xor(a_1 thorugh a_5) xor s_6 xor s_7 xor s_8, which is xor(a_1 through a_5) xor s_8
 * if (x / 2 <= n) we calculate directly
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n;
		ll l, r; 
		cin >> n >> l >> r;
		
		vector<int> a(n, 0);
		for (int &x : a) cin >> x;
		vector<int> p(n + 1, 0); // xor[i] = xor[a1...ai] (one indexed)
					 //
		for (int i = 1; i <= n; i++) {
			p[i] = a[i - 1] ^ p[i - 1];
		}

		// create even parity
		if (n % 2 == 0) {
			a.push_back(p[n / 2]);
			p.push_back(p.back() ^ p[n / 2]);
			n++;
		}


		auto solve = [&](this auto solve, ll x) -> int {
			if (x <= n) {
				return a[x - 1];
			} else if (x / 2 <= n) {
				return p[x / 2];
			} else {
				return p[n] ^ (((x / 2 - n) & 1) ? solve(x / 2) : 0);
			}
		};

		/*vector<int> b(l, 0);
		for (int i = 1; i <= n; i++) {
			b[i] = a[i - 1];
		}
		for (int i = n + 1; i <= l; i++) {
			int cur = 0;
			for (int j = 1; j <= i / 2; j++) {
				cur ^= b[j];
			}
			b[i] = cur;
			cout << "trying to solve i: " << i << '\n';
			if (solve(i) != cur) {
				cout << "mismatch on number " << i << '\n';
				cout << "should be " << cur << " but is actually " << 1 - cur << '\n';
			}
		}
		*/


		cout << solve(l) << '\n';
	}
}



