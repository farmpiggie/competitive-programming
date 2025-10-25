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
		bool works = b[n - 1] == a[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			if (b[i] != a[i] && b[i] != (a[i] ^ b[i + 1]) && b[i] != (a[i] ^ a[i + 1])) {
				//cout << a[i] << " " << a[i + 1] << " " << (a[i] ^ a[i + 1]) << b[i] << '\n';
				//cout << "i: " << i << '\n';
				works = false;
				break;
			}
		}
		cout << (works ? "YES" : "NO") << '\n';
	}
}
