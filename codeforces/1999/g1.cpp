/*
ternary search?

first guess would be 333, 666
if return = 334 * 667, we know the error is in the first third
if return = 333 * 667, we know the error is in the second half
if return = 333 * 666, we know the error is in the third half
etc etc

answer is found when:
left + 1 = right
and return is left * (right + 1)


*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int answer = 0;

ll ask(int a, int b) {
	cout << "? " << a << " " << b << endl;
	
	ll ret; cin >> ret;

	// testing
	// ll ret = 1;
	// if (a >= answer) ret *= a + 1;
	// else ret *= a;
	// if (b >= answer) ret *= b + 1;
	// else ret *= b;

	return ret;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {

		// testing
		// cin >> answer;

		ll lo = 1, hi = 1000;
		ll ans = 0;
		while (lo <= hi) {
			ll left = lo + (hi - lo) / 3;
			ll right = lo + (hi - lo) * 2 / 3;
			ll x = ask(left, right);
			if (x == left * right) {
				lo = right + 1;
				ans = max(ans, lo);
			} else if (x == (left + 1) * (right + 1)) {
				hi = left - 1;
			} else { // left right, right wrong
				lo = left, hi = right;
			}
			if (left == right) { // found
				break;
			}
		}
		cout << "! " << ans << endl;
	}
	return 0;
}
