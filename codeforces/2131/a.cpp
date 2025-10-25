#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n), b(n);
		for (int &x : a) cin >> x;
		for (int &x : b) cin >> x;
		
		int add = 0, subtract = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] > b[i]) {
				subtract += a[i] - b[i];
			} else if (a[i] < b[i]) {
				add += b[i] - a[i];
			}
		}
		cout << subtract + 1 << '\n';
	}
}