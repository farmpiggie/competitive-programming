#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	// ifstream cin("hossamfriends.in");
	int t; cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		// dp[i] = # of segments ending at arr[i] that are "GOOD"
		// dp[i] = 1;
		// if (dp)
		int a, b;
		vector<int> unmatched(n + 1, 0); // should all be n + 1
 		for (int i = 0; i < m; i++) {
 			cin >> a >> b;
 			if (a > b) swap(a, b);
 			unmatched[b] = max(unmatched[b], a); // biggest value that doesnt match here
		}
		// if (2, 3) is not a match, then (1, 3) also can never be one
		ll ans = 0;
		int curr = 0;
		for (int i = 1; i <= n; i++) {
			// all n values
			curr = max(curr, unmatched[i]);
			ans += (i - curr);
			// cout << "matches for substrings ending at: " << i << ": " << i - curr << endl;
		}
		cout << ans << endl;
	}
	return 0;
}