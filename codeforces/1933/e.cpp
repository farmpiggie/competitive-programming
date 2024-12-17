#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {	
		cin >> a[i];
		if (i) a[i] += a[i - 1];
	}

	int q; cin >> q;
	while (q--) {
		int l, u; cin >> l >> u; l--;

		int left = l, right = n - 1;
		l = l ? a[l - 1] : 0;
		while (right > left) {
			int mid = (left + right + 1) / 2;
			if (a[mid] - l <= u) left = mid;
			else right = mid - 1;
		}
		
		if (left < n - 1 && a[left + 1] - l - u <= u - (a[left] - l)) left++;
		cout << left + 1 << ' ';
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t; while (t--) solve();
}