#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		map<int, int> mp;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			mp[x]++;
		}
		for (int i = 1; i <= sqrt(n - 2); i++) {
			if ((n - 2) % i == 0) {
				int j = (n - 2) / i;
				if ((i == j && mp[i] >= 2) || (i != j && mp[i] > 0 && mp[j] > 0)) {
					cout << i << " " << j << '\n';
					break;
				}
			}
		}
	}
	return 0;
}
