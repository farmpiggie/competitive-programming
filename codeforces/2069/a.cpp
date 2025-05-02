/*
 * 101 is not possible as a sequence
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n - 2);
		for (int &x : a) cin >> x;
		bool works = true;
		for (int i = 2; i < n - 2; i++) {
			if (a[i - 2] && !a[i - 1] && a[i]) {
				works = false;
				break;
			}
		}
		cout << (works ? "YES" : "NO") << '\n';
	}
}

