#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int a, b, d, e; cin >> a >> b >> d >> e;
		int c = a + b;
		int best = (a + b == c) + (b + c == d) + (c + d == e);
		c = d - b;
		best = max(best, (a + b == c) + (b + c == d) + (c + d == e));
		c = e - d;
		best = max(best, (a + b == c) + (b + c == d) + (c + d == e));
		cout << best << '\n';
	}
}
