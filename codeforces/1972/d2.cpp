#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll gcd(ll a, ll b) {
	if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		//	vector<vector<bool>> args((int) (sqrt(n) + 1), vector<bool>((int) (sqrt(m) + 1);
		ll ans = 0;			
		for (int i = 1; i <= sqrt(n); i++) {
			for (int j = 1; j <= sqrt(m); j++) {
				if (gcd(i, j) == 1) {
					ans += min(n / i, m / j) / (i + j);
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
