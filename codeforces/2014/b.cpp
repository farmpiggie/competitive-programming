#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		ll n, k; cin >> n >> k;
		int num_odds = (n % 2 == 0) ? k / 2 : (k - 1) / 2 + 1;
		if (num_odds % 2 == 0) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}