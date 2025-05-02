/*
 * rule of beautiful subsequence:
 * must start with 1
 * must end with 3
 * can only contain two in the middle
 * ex: 1 [1 or more twos] 3
 * dp
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll MOD = 998244353;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int &x : a) cin >> x;

		// keep track of # of twos seen thus far
		int ones = 0, twos = 0;
		ll cnt = 0;
		ll ans = 0;
		for (int x : a) {
			if (x == 1) {
				ones++;
				cnt = (cnt + 1) % MOD;
			} else if (x == 2) {
				twos++;
				cnt = (cnt * 2) % MOD;
			} else {
				ll res = (cnt - ones + MOD) % MOD;
				ans = (ans + res) % MOD;
			}
		}
		cout << ans << '\n';
	}
}

