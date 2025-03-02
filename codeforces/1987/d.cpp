#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		map<int, int> occ;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			occ[x]++;
		}
		n = occ.size();
		vector<int> a;
		for (auto [_, x] : occ) {
			a.push_back(x);
		}

		vector<int> dp(n + 1, INF);
		dp[0] = 0;
		for (int i = 1; i <= n; i++) {
			vector<int> ndp = dp;
			for (int j = 1; j <= n; j++) {
				int cost = dp[j - 1] + a[i - 1];
				if (cost <= i - j) {
					ndp[j] = min(ndp[j], cost);
				}
			}
			dp = ndp;
		}

		int ans = n;
		while (dp[ans] >= INF) ans--;
		cout << n - ans << '\n';
	}
}


