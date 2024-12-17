#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 5;
int t, a[N];

void solve() {
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);

	ll steps = 0;
	int x = 0;
	int l = 0, r = n - 1;
	while (l < r) {
		if (a[l] + x > a[r]) { // consume part of l to eliminate r
			int diff = a[r] - x;
			a[l] -= a[r] - x;
			steps += (a[r] - x + 1);
			a[r] = 0;
			r--;
			x = 0;
		} else {	// consume entirety of l
			x += a[l];
			steps += a[l];
			l++;
		}
	}
	// l should equal r
	if (x >= a[l]) steps++;
	else {
		if (a[l] == 1) steps++;
		else steps += (a[l] - x + 1) / 2 + 1;
	}
	cout << steps << endl;
}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}