#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		vector<int> arr(3);
		for (int& x : arr) cin >> x;

		vector<int> ans(3, 0);
		for (int i = 0; i < 3; i++) {
			int a = arr[i], b = arr[(i + 1) % 3], c = arr[(i + 2) % 3];
			// can we make the array all c?
			if (abs(a - b) % 2 == 0) ans[(i + 2) % 3] = 1;
		}
		for (int x : ans) cout << x << " ";
		cout << '\n';
	}
}
			
