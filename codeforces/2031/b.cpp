#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		bool wrong = false;
		bool works = true;
		for (int i = 0; i < n; i++) {
			if (a[i] == i + 1) continue;
			else if (!wrong) {
				wrong = true;
			} else {
				swap(a[i - 1], a[i]);
				if (a[i - 1] != i || a[i] != i + 1) {
					works = false;
					break;
				} else {
					wrong = false;
				}
			}
		}
		cout << (works ? "YES" : "NO") << '\n';
	}
	return 0;
}
