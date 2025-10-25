#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int &x : a) cin >> x;
		sort(a.begin(), a.end());

		int odds = 0, evens = 0;
		for (int x : a) {
			if (x & 1) odds++;
			else evens++;
		}
		if (evens == 0 || odds == 0) {
			cout << a.back() << '\n';
			continue;
		}
		// at least one odd and one even
		ll ans = 0;
		for (int x : a) ans += x;
		ans -= (odds - 1);
		cout << ans << '\n';


	}
}