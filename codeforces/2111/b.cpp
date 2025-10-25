/*
 * we know that all n - 1 fib boxes could fit in the nth fib box
 * 1^2 + 1^2 + 2^2 < 3^2
 * 1^2 + 1^2 + 2^2 + 3^2 < 5^2
 * we know that the biggest box must fit on the bottom
 * oh.
 * i think if it can fit the first two boxes it just works
 * LOL
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);;
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<int> fib = {1, 1, 2};
		for (int i = 3; i <= n; i++) {
			fib.push_back(fib.back() + fib[fib.size() - 2]);
		}

		for (int i = 0; i < m; i++) {
			int w, l, h; cin >> w >> l >> h;
			int big = fib.back(), second_big = fib[fib.size() - 2];
			if (w < big || l < big || h < big || (w < big + second_big && l < big + second_big && h < big + second_big)) {
				cout << '0';
			} else {
				cout << '1';
			}
		}
		cout << '\n';
	}
}
