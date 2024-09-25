#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, m, k, d;
		cin >> n >> m >> k >> d;
		vector<vector<int>> a(n, vector<int>(m, 0));
		for (auto& b : a)
			for (int& x : b)
				cin >> x;

		vector<ll> psum(n, 0);
		for (int i = 0; i < n; i++) {
			deque<int> dq;
			vector<ll> dp(m, 0);
			dp[0] = 1;
			dq.push_back(0);
			for (int j = 1; j < m; j++) {
				if (dq.front() == j - d - 2) dq.pop_front();
				
				dp[j] = a[i][j] + 1 + dp[dq.front()];

				while (!dq.empty() && dp[j] <= dp[dq.back()]) {
					dq.pop_back();
				}
				dq.push_back(j);
			}
			psum[i] = dp[m - 1] + (i ? psum[i - 1] : 0);
		}
		ll ans = LLONG_MAX;
		for (int i = k - 1; i < n; i++) {
			ans = min(ans, psum[i] - (i - k >= 0 ? psum[i - k] : 0)); 
		}
		cout << ans << '\n';
	}
}
