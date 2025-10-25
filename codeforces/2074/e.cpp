#include <bits/stdc++.h>
using namespace std;

int query(int x, int y, int z) {
	cout << "? " << x << " " << y << " " << z << endl;
	int res; cin >> res;
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> pts = {1, 2, 3};
		int m = query(pts[0], pts[1], pts[2]);
		while (m != 0) {
			pts[rand() % 3] = m;
			m = query(pts[0], pts[1], pts[2]);
		}
		cout << "! " << pts[0] << " " << pts[1] << " " << pts[2] << endl;
	}
}