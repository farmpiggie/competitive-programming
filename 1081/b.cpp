#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	map<int, vector<int>> mp; // mp[a[i]] = list of indices
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		mp[x].push_back(i);
	}
	vector<int> ans(n);
	bool works = true;
	int hat = 1;
	for (auto& [a, inds] : mp) {
		if (inds.size() % (n - a) == 0) {
			for (int i = 0; i < inds.size(); i += (n - a)) {
				for (int j = 0; j < n - a; j++) {
					ans[inds[i + j]] = hat;
				}
				hat++;
			}
		} else {
			works = false;
			break;
		}
	}
	if (works) {
		cout << "Possible\n";
		for (int x : ans) cout << x << " ";
		cout << '\n';
	} else cout << "Impossible\n";
	return 0;
}

