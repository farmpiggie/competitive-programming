#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int t, n, m, a[N], b[N];

void solve() {
	cin >> n >> m;
	a[1] = 1;
	for (int i = 2; i <= n; i++) 
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);

	int lo = 0, hi = n;
	int best = n;
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		bool works = true;
		for (int i = 1, j; i <= n - (mid); i++) {
			j = i + mid;
			if (a[i] >= b[j]) {
				works = false;
				break;
			}
		}
		if (works) {
			best = min(best, mid);
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	cout << best << "\n";
}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}