// cyclic shift = move back character to front
#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int ones = 0;
		int zeros = 0;
		ll ans = 0;
		for (char c : s) {
			if (c == '0') {
				if (ones > 0) ans += ones + 1;
			} else {
				ones++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
