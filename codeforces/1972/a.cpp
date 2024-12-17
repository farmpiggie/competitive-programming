// if last problem is the only one with issues, we can solve this by simply adding a problem of difficulty min(a_0, b_0)
// do this at most O(n) times?
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n), b(n);
		for (int& x : a) cin >> x;
		for (int& x : b) cin >> x;
		list<int> l;
		for (int& x : a) l.push_back(x);

		for (int i = 0; i <= n; i++) {
			bool works = true;
			for (int j = 0; j < n; j++) {
				if (j < i) {
					if (min(a[0], b[0]) > b[j]) {
						works = false;
					}
				} else {
					if (a[j - i] > b[j]) {
						works = false;
					}
				}
			}
			if (works) {
				cout << i << '\n';
				break;
			}
		}
	}
}

