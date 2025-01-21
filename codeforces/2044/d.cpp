#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		set<int> seen;
		vector<int> ans;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			if (!seen.count(x)) ans.push_back(x);
			seen.insert(x);
		}
		for (int i = 1; i <= n; i++) {
			if (!seen.count(i)) ans.push_back(i);
		}
		for (int x : ans) cout << x << " ";
		cout << '\n';
	}
	return 0;
}
		
