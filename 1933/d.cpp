#include <bits/stdc++.h>
using namespace std;

int t, n;
vector<int> a;
int main() {
	cin >> t;
	while (t--) {

		cin >> n;
		a.resize(n);

		for (int& x : a) {
			cin >> x;
		}

		sort(a.begin(), a.end());

		int num_lowest = upper_bound(a.begin(), a.end(), a[0]) - lower_bound(a.begin(), a.end(), a[0]);
		bool works = false;

		if (num_lowest == 1) {
			works = true;
		}

		for (int& x : a) {
			if (x % a[0] != 0) {
				works = true;
			}
		}

		if (works) cout << "YES\n";
		else cout << "NO\n";

	}
	return 0;
};