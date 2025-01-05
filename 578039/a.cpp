/*
 * x2, x4, x6 represent gaps between perfect squares.
 *
 * for each value, we need to find gaps of said size.
 *
 * if diff is odd:
 *     let a[i] = 2 * x + 1;
 *     (x + 1)^2 - x^2 = 2x + 1, 
 *     prev sum must equal x^2
 *
 *
 * else if diff % 4 == 0:
 *     let a[i] = 4x
 *     (x + 1)^2 - (x - 1)^2 = 4x
 *     prev sum must equal (x - 1)^2
 *
 * issue with construction: number acn grow too fast? therefore x * x - sum is too large.
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX = 1e13;

int main() {
	int n; cin >> n;
	vector<ll> arr(n);
	for (int i = 0; i < n / 2; i++) {
		cin >> arr[i * 2 + 1];
	}
	for (int i = 0; i < n; i += 2) {
		arr[i] = LLONG_MAX;
	}
	bool works = true;
	ll sum = 0;
	for (int i = 1; i < n; i++) {
		if (i % 2) {
			// range is [sum], x, a[i]
			// sum + x is square, sum + x + a[i] is square.
			// therefore a[i] is the difference of two squares (sum + x, sum + x + a[i])
			// assign a^2 = sum + x + a[i], b^2 = sum + x
			// a^2 - b^2 = (a - b)(a + b) = a[i], let us try factors of a[i].
			// search through all sqrt(2e5) pairings, see which ones result in smallest b s.t. b > sum.
			// therefore x = sum - b.
			bool found = false;
			for (ll j = 1; j * j <= arr[i]; j++) {
				if (arr[i] % j != 0) continue;
				ll k = arr[i] / j;
//				cout << "factors: " << j << " " << k << '\n';
				// (a - b) = i, (a + b) = j
				// a = (j + k) / 2
				// sum is supposed to be a^2,
				if ((j + k) % 2 == 1) continue;
				ll a = (j + k) / 2, b = k - a;
//				cout << "a and b: " << a << " " << b << '\n';
			       	if (b * b > sum) {
//					cout << "x: " << b * b - sum << '\n';
					found = true;
					arr[i - 1] = min(arr[i - 1], b * b - sum);
				}
			}
			sum += arr[i - 1] + arr[i];
			if (!found) {
				works = false;
				break;
			}		
		}
	}
	if (works) {
		cout << "Yes\n";
		for (ll x : arr) cout << x << " ";
		cout << '\n';
	} else cout << "No\n";
	return 0;
}
