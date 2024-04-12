#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		string x, y; cin >> x >> y;
		int n = (int) x.size();
		
		int bigger = -1;
		for (int i = 0; i < n; i++) {
			if (bigger == -1) {
				if (x[i] > y[i]) bigger = 0;
				else if (x[i] < y[i]) bigger = 1;
			} else {
				if (bigger == 0 && x[i] > y[i]) {
					swap(x[i], y[i]);
				}
				if (bigger == 1 && x[i] < y[i]) {
					swap(x[i], y[i]);
				}
			}
		}

		cout << x << "\n" << y << " " << '\n';
	}
	return 0;
}
