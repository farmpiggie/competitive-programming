#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> arr(n);
		for (int& x : arr) cin >> x;
		map<int, int> mp;
		for (int& x : arr) mp[x]++;

		int ans = 0;
		for (auto& p : mp) ans = max(ans, p.second);
		cout << n - ans << '\n';
	}
}