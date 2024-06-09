// no need to remove numbers smaller than our MEX
// strive to always remove one set of #s first, then move on to a smaller set of #s
// minimize cost
//
#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int> 

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		vector<int> occ(5001, 0);
		for (int& x : a) {
			cin >> x;
			if (x <= 5000) occ[x]++;
		}
		sort(a.begin(), a.end());
		
		int mex = 0;
		for (int& x : a) {
			if (mex == x) mex++;
		}

		if (mex == 0) {
			cout << "0\n";
			continue;
		}

		vector<int> dp(5001, INT_MAX);
		dp[0] = 0;
		for (int i = 1; i < mex; i++) {
			for (int j = 0; j < i; j++) {
//				if (i == 1) cout << j << " " << dp[j] << " " << i * occ[j] << '\n';
				dp[i] = min(dp[i], dp[j] + i * occ[j]);
			}
		}
//		for (int i = 0; i < mex; i++) cout << dp[i] << ' ';
//		cout << '\n';
		int ans = INT_MAX;
		for (int i = 0; i < mex; i++) {
			ans = min(ans, dp[i] + mex * (occ[i] - 1));
		}
		cout << ans << '\n';
	}
	return 0;
}
