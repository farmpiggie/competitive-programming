// sends two invites if for some i and p[i], i = p[i] and p[p[i]] = i
// sends three invites if for some i and j,  p[i] = j and 

#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int& x : a) {
			cin >> x;
			--x;
		}
		bool works = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				if (a[i] == j && a[j] == i) works = true;
			}
		}
		if (works) cout << "2\n";
		else cout << "3\n";
	}
	return 0;
}
