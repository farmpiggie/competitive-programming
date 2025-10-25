/*
to find () in log(n):
if query(1, n) > 0, we cna binary search looking for query(x, y) > 0
problem is if query(1, n) < 0, we know the array takes the form )))))(((
we can binary search for a range (x, y) as 2 1 4 3 etc. and use this to find those values
*/
#include <bits/stdc++.h>
using namespace std;

int ask(int l, int r) {
	cout << "? " << r - l + 1 << ' ';
	for (int i = l; i <= r; i++) cout << i << ' ';
	cout << '\n' << flush;
	int x; cin >> x;
	return x;
}

int ask_flip(int len) {
	cout << "? " << len << ' ';
	for (int i = 2; i <= len; i++) {
		cout << i << ' ';
	}
	cout << 1 << '\n' << flush;
	int x; cin >> x;
	return x;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int none = ask(1, n);
		if (none == 0) { // ))))(((
			int l = 1, r = n;
			int mn = n;
			while (l <= r) {
				int m = (l + r) / 2;
				if (ask_flip(m) > 0) {
					mn = min(mn, m);
					r = m - 1;
				} else {
					l = m + 1;
				}
			}
			// mn should have the first ( value
			cout << "! ";
			for (int i = 1; i < mn; i++) {
				cout << ')';
			}
			for (int i = mn; i <= n; i++) {
				cout << '(';
			}
			cout << '\n' << flush;	
		} else {
			int l = 1, r = n;
			int open = -1, close = -1; // open and close indices
			while (l < r) {
				int m = (l + r) / 2;
				if (ask(m, m + 1) == 1) {
					open = m;
					close = m + 1;
					break;
				} else if (ask(l, m) > 0) {
					r = m; // could be (m - 1, m)
					if (l + 1 == m) {
						open = l;
						close = m;
						break;
					}
				} else {
					l = m + 1; // cant include m since we tried (m, m + 1)
				}
			}
			assert(open != -1);
			assert(close != -1);
			auto ask2 = [&](int x, int y) -> int {
				cout << "? 7 " << open << ' ' << open << ' ' << x << ' ' << y << ' ' << x << ' ' << y << ' ' << close << '\n' << flush;
				int res; cin >> res;
				return res;
			};
			vector<string> ans;
			for (int i = 2; i <= n; i += 2) {
				int res = ask2(i - 1, i);
				if (res == 4) {
					ans.push_back("()");
				} else if (res == 6) {
					ans.push_back(")(");
				} else if (res == 2) {
					ans.push_back("))");
				} else {
					ans.push_back("((");
				}
			}
			if (n % 2 == 1) {
				cout << "? 2 " << open << ' ' << n << '\n' << flush;
				int res; cin >> res;
				if (res == 1) {
					ans.push_back(")");
				} else {
					ans.push_back("(");
				}
			}
			cout << "! ";
			for (string& s : ans) cout << s;
			cout << '\n' << flush;
		}
	}
}



				








					
