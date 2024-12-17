#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

// 2 5 5 4 2 5 5 4

int t, n, a[MAXN];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// go to left
	int ans = MAXN;
	int ascending_errors = 0;
	int descending_errors = 0;
	for (int i = 1; i < n; i++) {
		if (a[i - 1] > a[i]) ascending_errors++;
		else if (a[i - 1] < a[i]) descending_errors++;
	}
	

	if (ascending_errors == 0) ans = 0;
	else if (descending_errors == 0) ans = 1;


	for (int i = 1; i <= n; i++) {
		int x = ((n - i) + n) % n; // element added on the left is the one removed from the right.
		if (a[x] > a[(x + 1) % n]) ascending_errors++;
		if (a[x] < a[(x + 1) % n]) descending_errors++;

		if (a[x] > a[(x - 1 + n) % n]) descending_errors--;
		if (a[x] < a[(x - 1 + n) % n]) ascending_errors--;

		if (ascending_errors == 0) {
			ans = min(ans, i);
		} 
		if (descending_errors == 0) {
			ans = min(ans, i + 1); // need to reverse
		}
	}

	reverse(a, a + n);
	ascending_errors = 0;
	descending_errors = 0;
	for (int i = 1; i < n; i++) {
		if (a[i - 1] > a[i]) ascending_errors++;
		else if (a[i - 1] < a[i]) descending_errors++;
	}

	for (int i = 1; i <= n; i++) {
		int x = ((n - i) + n) % n; // element added on the 
		if (a[x] > a[(x + 1) % n]) ascending_errors++;
		if (a[x] < a[(x + 1) % n]) descending_errors++;

		if (a[x] > a[(x - 1 + n) % n]) descending_errors--;
		if (a[x] < a[(x - 1 + n) % n]) ascending_errors--;

		if (ascending_errors == 0) {
			ans = min(ans, i + 1);
		} 
		if (descending_errors == 0) {
			ans = min(ans, i + 2); // need to reverse
		}
	}
	if (ans == MAXN) cout << "-1\n";
	else cout << ans << '\n';
}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}