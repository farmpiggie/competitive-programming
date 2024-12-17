#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

int t, n, k, x, a[MAXN], pre[MAXN];

void solve() {
	cin >> n >> k >> x;
	for (int i = 0; i < n; i++) 
		cin >> a[i];

	sort(a, a + n);
	pre[0] = a[0];
	for (int i = 0; i < n; i++) {
		pre[i] = pre[i - 1] + a[i];
	}

	int ans = pre[n - 1];
	int bob;
	bob = pre[n - 1] - pre[n - 1 - x];
	ans -= 2 * bob;
	int sum = pre[n - 1];
	for (int i = 0; i < k; i++) { // try to remove elements
		sum -= a[n - 1 - i];
		// cout << "removing the value of " << a[n - 1 - i] << '\n';
		// if i remove all elements up to n - 1 - i, then i should have elements
		// b removes x elements
		bob = 0;
		if (n - 2 - i >= 0) {
			bob = pre[n - 2 - i];
		} 
		if (n - 2 - i - x >= 0) {
			bob -= pre[n - 2 - i - x];
		}
		// cout << "removing the summation twice: " << bob << '\n';
		int temp = sum;
		temp -= 2 * bob;
		// cout << "temp sum: " << temp << '\n';
		ans = max(ans, temp);
	}
	cout << ans << '\n';


}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}