#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, q; cin >> n >> q;
		vector<int> a(n);
		for (int &x : a) cin >> x;
		vector<int> ones(n + 1), zeros(n + 1);
		vector<pair<int, int>> alternate;
		int l = 1;
		ones[1] = (a[0] == 1);
		zeros[1] = (a[0] == 0);
		for (int i = 1; i < n; i++) {
			if (a[i] == a[i - 1]) {
				alternate.push_back({l, i});
				l = i + 1;
			}
			ones[i + 1] = ones[i] + (a[i] == 1);
			zeros[i + 1] = zeros[i] + (a[i] == 0);
		}
		alternate.push_back({l, n});
		while (q--) {
			int x, y; cin >> x >> y;
			int tot_ones = ones[y] - ones[x - 1];
			int tot_zeros = zeros[y] - zeros[x - 1];
			if (tot_ones % 3 != 0 || tot_zeros % 3 != 0) {
				cout << "-1\n";
				continue;
			}
			auto it = upper_bound(alternate.begin(), alternate.end(), make_pair(x + 1, 0)); // first element bigger than this
			--it; // always an element smaller.
			if (it->first <= x && y <= it->second) {
				cout << (y - x + 1) / 3 + 1 << '\n';
			} else {
				cout << (y - x + 1) / 3 << '\n';
			}
		}
	}
}

