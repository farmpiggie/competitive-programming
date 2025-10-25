#include <bits/stdc++.h>
using namespace std;


int main() {
	// ifstream cin("restorethepermutation.in");
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> b(n / 2);
		vector<int> ans(n);
		set<int> s;

		for (int i = 1; i <= n; i++) {
			s.insert(i);
		}

		for (int i = 0; i < n / 2; i++) {
			cin >> b[i];
			ans[2 * i + 1] = b[i];
			auto it = s.find(b[i]);
			if (it != s.end()) s.erase(it);
		}

		if (s.size() != n / 2) {
			cout << -1 << endl;
			continue;
		}
		// s is what remains
		bool possible = true;

		int curr_index = 0;
		for (int i = n / 2 - 1; i >= 0; i--) {
			auto it = s.lower_bound(b[i]);
			if (it == s.begin()) {
				possible = false;
				break;
			} else {
				int num = *(--it);
				if (num < ans[2 * i + 1]) {
					ans[2 * i] = num;
					ans[2 * i + 1] = b[i];
					s.erase(it);
				} else {
					possible = false;
					break;
				}
				
			}
		}

		if (!possible) cout << -1 << endl;
		else {
			for (int i : ans) cout << i << " ";
				cout << endl;
		}

	}
	return 0;
}