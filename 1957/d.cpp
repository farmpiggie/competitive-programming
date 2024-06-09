// f(x, y) ^ f(y, z) = f(x, z) ^ a_y
// now we are solving for whether or not f(x, z) ^ a_y = f(x, z)
// we know if a ^ b > a if:
// call xth bit = bit position of MSB of b with value 1
// xth bit of A must be 0
// tuple (x, y, z) works if f(x, z) has a 0 at the xth bit of a_y
// OKAY 
// what i should do is: 
// dp[i][j] = # of arrays ending at index i with bit i set
// dp2[i][j] = # of arrays starting at index i with bit i set
#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		vector<vector<ll>> lft(n, vector<ll>(32, 0));
		vector<vector<ll>> r(n, vector<ll>(32, 0));
		vector<int> msb(n, 0);

		for (int i = 0; i < n; i++) {
			for (int j = 31; j >= 0; j--) {
				if ((a[i] >> j) & 1) {
					msb[i] = j;
					break;
				}
			}
		}

		for (int j = 0; j < 32; j++) {
			if ((a[0] >> j) & 1) lft[0][j] = 1;
			else lft[0][j] = 0;
		}

		for (int i = 1; i < n; i++) {
			for (int j = 0; j < 32; j++) {
				if ((a[i] >> j) & 1) {
					lft[i][j] = i - lft[i - 1][j] + 1;
				} else {
					lft[i][j] = lft[i - 1][j];
				}
			}
		}

		for (int j = 0; j < 32; j++) {
			if ((a[n - 1] >> j) & 1) r[n - 1][j] = 1;
			else r[n - 1][j] = 0;
		}

		for (int i = n - 2; i >= 0; i--) {
			for (int j = 0; j < 32; j++) {
				if ((a[i] >> j) & 1) {
					r[i][j] = (n - i - 1) - r[i + 1][j] + 1;
				} else {
					r[i][j] = r[i + 1][j];
				}
			}
		}
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			ans += lft[i][msb[i]] * (n - i - r[i][msb[i]]) + (i + 1 - lft[i][msb[i]]) * r[i][msb[i]];
		}
		cout << ans << '\n';

	}
	return 0;
}
