// create as many triangles as possible
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		map<int, int> mp;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			mp[x]++;
		}
		int ans = 0;
		for (auto& p : mp) {
			ans += (p.second / 3);
		}
		cout << ans << '\n';
	}
	return 0;
}
