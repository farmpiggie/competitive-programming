#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	vector<int> dp(n, 1);
	int ans = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i] % a[j] == 0) dp[i] = max(dp[i], dp[j] + 1);
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << '\n';
}
