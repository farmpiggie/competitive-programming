#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << n << " ";
		for (int i = n - 1; i >= 1; i--) cout << i << " ";
		cout << n << " ";
		for (int i = 1; i < n; i++) cout << i << " ";
		cout << '\n';
	}
}
