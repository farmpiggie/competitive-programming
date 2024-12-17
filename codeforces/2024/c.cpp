#include <bits/stdc++.h>
using namespace std;

/*

*/

#define vi vector<int>
#define v2i vector<vector<int>>

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		v2i a(n, vi(2, 0));
		for (int i = 0; i < n; i++) {
			cin >> a[i][0] >> a[i][1];
		}
		sort(a.begin(), a.end(), [](const vector<int>& b, const vector<int>& c) {
			if (min(b[0], b[1]) == min(c[0], c[1])) return max(b[0], b[1]) < max(c[0], c[1]);
			else return min(b[0], b[1]) < min(c[0], c[1]);
		});
		for (const vi& x : a) cout << x[0] << " " << x[1] << " ";
		cout << '\n';
	}
	return 0;
}