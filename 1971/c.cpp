// let a < b, c < d, let a < b
// check if a < c < b < d
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		int w, x, y, z; 
		w = min(a, b);
		x = max(a, b);
		y = min(c, d);
		z = max(c, d);
		if (w > y) {
			swap(w, y);
			swap(x, z);
		}
		if (w < y && y < x && x < z) cout << "YES\n";
		else cout << "NO\n";
	}
}
