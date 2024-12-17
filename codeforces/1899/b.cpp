#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int t, n, a[N]; 

typedef long long ll;

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	vector<int> factors;

	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			factors.push_back(i);
			factors.push_back(n / i);
		}
	}
	
	ll ans = 0;
	for (int factor : factors) {
		// cout << "size of k: " << factor << endl;
		ll big = 0, small = LLONG_MAX;
		for (int i = 0; i < n; i += factor) {
			ll curr = 0;
			for (int j = i; j < i + factor; j++) {
				curr += a[j];
			}
			// cout << "curr: " << curr << endl;
			big = max(big, curr);
			small = min(small, curr);
		}
		// cout << "big: " << big << endl;
		// cout << "small: " << small << endl;
		ans = max(ans, big - small);
	}

	cout << ans << endl;
}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}