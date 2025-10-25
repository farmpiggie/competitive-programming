#include <bits/stdc++.h>
using namespace std;

void solve() {
	int m; cin >> m;
	vector<set<int>> arr(m);
	for (int i = 0; i < m; i++) {
		int n; cin >> n;
		for (int j = 0; j < n; j++) {
			int a; cin >> a;
			arr[m - 1 - i].insert(a);
		}
	}

	// start from the first set
	// check between all sets if arr[i] has at least one number arr[i - 1] doesn't have
	set<int> seen;
	for (int num : arr[0]) seen.insert(num);
	vector<int> ans;
	ans.push_back(*arr[0].begin()); // any number in the last row
	bool works = true;
	for (int i = 1; i < m; i++) {
		works = false;
		for (int num : arr[i]) {
			if (!seen.count(num)) {
				works = true;
				ans.push_back(num);
				break;
			}
		}
		for (int num : arr[i]) seen.insert(num);
		if (!works) { cout << "-1" << endl; return; }
	}
	reverse(ans.begin(), ans.end());
	for (int val : ans) cout << val << " ";
	cout << endl;
}

int main() {
	int t; cin >> t;
	while (t--) solve();
	return 0;
}