#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		map<int, int> mp; // mp[brand] = sum cost of all bottles
		for (int i = 0; i < k; i++) {
			int b, c; cin >> b >> c;
			mp[b] += c;
		}
		vector<pair<int, int>> arr;
		for (auto& [x, y] : mp) arr.push_back({y, x});
		sort(arr.begin(), arr.end());
		reverse(arr.begin(), arr.end());

		int ans = 0;
		for (int i = 0; i < min(n, (int) arr.size()); i++) {
			ans += arr[i].first;
		}	
		cout << ans << '\n';
	}
	return 0;
}