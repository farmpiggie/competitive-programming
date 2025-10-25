// https://codeforces.com/contest/1759/problem/B
#include <bits/stdc++.h>
using namespace std;
int main() {
	// ifstream cin("lostperm.in");

	int t; cin >> t;
	while (t--) {
		int m, s; 
		cin >> m >> s;
		int curr_sum = 0;
		int mx = 0;
		for (int i = 0; i < m; i++) {
			int a; cin >> a;
			curr_sum += a;
			mx = max(mx, a);
		}
		int total = s + curr_sum;


		bool works = false;
		int lo = mx, hi = 100; // good enough
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			int temp = mid * (mid + 1) / 2;
			if (temp == total) {
				works = true;
				break;
			} else if (temp < total) {
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		} 
		if (works) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}