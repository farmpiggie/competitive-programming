/*
 * if both sides of a gate are addition, doesn't really change outcome.
 * for our multipliers (2x, 3x) we usually want more people to be going through these gates.
 *
 * everytime we gain people, we allocate them on one of two sides.
 * we have 1e4 test cases, n <= 30
 * just greedy.
 *
 * 1 1 (+10)
 * 1 11 (+23)
 * 24 11 (+19)
 * 43 11 (+44)
 * 98
 *
 */
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;

		vector<pair<char, int>> l(n), r(n);
		for (int i = 0; i < n; i++) {
			cin >> l[i].first >> l[i].second >> r[i].first >> r[i].second;
		}

		ll lhs = 1, rhs = 1;
		ll extra = 0;
		
		for (int i = 0; i < n; i++) {
			if (l[i].first != r[i].first) { // one +, one *
				if (l[i].first == 'x') {
					lhs += extra;
					extra = lhs * (l[i].second - 1) + r[i].second;
				} else {
					rhs += extra;
					extra = rhs * (r[i].second - 1) + l[i].second;
				}
			} else if (l[i].first == 'x' && l[i].first == 'x') { // one 2x, one 3x
				if (l[i].second != r[i].second) {
					if (l[i].second == 3) {
						lhs += extra;
					} else {
						rhs += extra;
					}
					extra = lhs * (l[i].second - 1) + rhs * (r[i].second - 1);
				} else {
					extra += (lhs + rhs + extra) * (l[i].second - 1);
				}
			} else { // both + +
				extra += l[i].second + r[i].second;
			}
		}
		cout << lhs + rhs + extra << '\n';
	}
}
					

			




