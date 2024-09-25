#include <bits/stdc++.h>
using namespace std;

#define ll long long

int t, a, b, l;
int main() {
	cin >> t;
	while (t--) {
		cin >> a >> b >> l;
		set<ll> s;
		ll a_x = 1;
		for (int x = 0; a_x <= l; x++) {
			ll b_y = 1;
			for (int y = 0; b_y <= l; y++) {
				if (l % (a_x * b_y) == 0) {
					s.insert(l / (a_x * b_y));
				}
				b_y *= b;
			}
			a_x *= a;
		}
		cout << (int) s.size() << '\n';

	}
	return 0;
}