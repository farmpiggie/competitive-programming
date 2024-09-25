#include <bits/stdc++.h>
using namespace std;

#define send ios::sync_with_stdio(false);
#define help cin.tie(NULL);
#define f first
#define s second
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

int t, n;

int main() {
	send help
	cin >> t;
	while (t--) {
		cin >> n;
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			ans += abs(x);
		}
		cout << ans << '\n';
	}
	return 0;
}