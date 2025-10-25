#include <bits/stdc++.h>
using namespace std; 

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int &x : a) cin >> x;

		sort(a.begin(), a.end());

		cout << a.back() - a[0] << '\n';
	}
}