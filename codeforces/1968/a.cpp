#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int x; cin >> x;
		int largest = 0;
		int best = -1;
		for (int y = 1; y < x; y++) {
			int cur = gcd(x, y) + y;
			if (cur > best) {
				largest = y;
				best = cur;
			}
		}
		cout << largest << '\n';
	}
	return 0;
}
