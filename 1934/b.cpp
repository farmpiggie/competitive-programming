#include <bits/stdc++.h>
using namespace std;

void run() {
	int n; cin >> n;
	int ans = n;
	for (int a = 0; a <= 2; a++) {
		for (int b = 0; b <= 1; b++) {
			for (int c = 0; c <= 4; c++) {
				for (int d = 0; d <= 2; d++) {
					int val = (n - a - b * 3 - c * 6 - d * 10);
					if (val >= 0 && val % 15 == 0) {
						ans = min(ans, val / 15 + a + b + c + d);
					}
				}
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t; while (t--) run();
	return 0;
}