#include <bits/stdc++.h>
using namespace std;

#define ll long long

// keep track of prefix sums for d <= sqrt(n), for all starting positions...
// for d > sqrt(n), just brute force

#define MAXN 100005

#define SQRT 320

int t, n, q;
ll a[MAXN];

void solve() {
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int m = floor(sqrt(n));

	// calculate all psums up to sqrt(n)

	vector<vector<ll>> psum(m + 1, vector<ll>(n)); 
    vector<vector<ll>> tot(m + 1, vector<ll>(n));

    for (int d = 1; d <= m; d++) {
    	for (int j = 0; j < n; j++) {
    		if (j - d >= 0) {
    			psum[d][j] += psum[d][j - d];
    			tot[d][j] += tot[d][j - d];
    		}
    		psum[d][j] += a[j];
    		tot[d][j] += (j / d + 1) * a[j];
    	}
    }

	// process queries

	int s, d, k;
	for (int i = 0; i < q; i++) {
		cin >> s >> d >> k;
		s--;

		ll ans = 0;

		if (d <= (int) sqrt(n)) {
			
			// cout << "using start with index: " << start << '\n';

			int end = s + (k - 1) * d;
			int start = s - d;


			ans += tot[d][end];
			if (start >= 0) {
				ans -= tot[d][start];
				ans -= (s / d) * (psum[d][end] - psum[d][start]);
			}
		} else {
			// cout << "brute force..." << '\n';
			int cnt = 1;
			for (int i = s; i <= s + d * (k - 1); i += d) {
				ans += 1ll * cnt * a[i];
				cnt++;
			}
		}
		cout << ans << ' ';

	}

	cout << '\n';


}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}