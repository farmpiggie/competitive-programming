/*
 * calculate first time that bot will hit pos 0 = a
 * then calculate when bot will hit zero starting from 0 = b
 * the # of times bot will hit zero in k seconds is max(0, k - a) / b + (k >= a)
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, x; ll k;
		cin >> n >> x >> k;
		string s; cin >> s;

		int pos = x;
		bool reached = false;
		int a = 0;
		for (char c : s) {
			if (c == 'L') pos--;
			else pos++;
			a++;
			if (pos == 0) {
				reached = true;
				break;
			}
		}

		if (!reached) {
			cout << "0\n";
			continue;
		}
		pos = 0;
		int b = 0;
		reached = false;
		for (char c : s) {
			if (c == 'L') pos--;
			else pos++;
			b++;
			if (pos == 0) {
				reached = true;
				break;
			}
		}
		ll ans = (k >= a);
		if (reached) ans += max(0ll, k - a) / b;
		cout << ans << '\n';
	}
}


