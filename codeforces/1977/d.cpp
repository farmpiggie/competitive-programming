#include <bits/stdc++.h>
using namespace std;

#define ll long long

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, m; 
		cin >> n >> m;
		char c;
		vector<vector<int>> a(n, vector<int>(m));
		for (auto& x : a) 
			for (int& y : x) {
				cin >> c;
				y = (c - '0');
			}

		vector<ll> rand1(n), rand2(n);
		for (ll& x : rand1) x = rnd();
		for (ll& x : rand2) x = rnd();
		
		map<pair<ll, ll>, int> cnt;
		int best = 0;
		pair<int, int> p = {0, 0};
		for (int j = 0; j < m; j++) {
			ll h = 0, h2 = 0;
			for (int i = 0; i < n; i++) {
				if (a[i][j]) {
					h ^= rand1[i];
					h2 ^= rand2[i];
				}	
			}

			for (int i = 0; i < n; i++) {
				h ^= rand1[i];
				h2 ^= rand2[i];
				cnt[{h, h2}]++;
				if (best < cnt[{h, h2}]) {
					best = max(best, cnt[{h, h2}]);
					p = {i, j};
				}
				h ^= rand1[i];
				h2 ^= rand2[i];
			}
		}


		cout << best << '\n';
		vector<int> ans(n, 0);
		for (int i = 0; i < n; i++) {
			if (a[i][p.second]) {
				if (i != p.first) ans[i] = 1;
			} else if (p.first == i) {
				ans[i] = 1;
			}
		}
		for (int& x : ans) cout << x;
		cout << '\n';
	}
	return 0;
}
