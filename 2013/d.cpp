#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<ll> a(n);
		for (ll& x : a) cin >> x;

		stack<pll> s;
		for (int i = 0; i < n; i++) {
			ll sum = a[i], cnt = 1;
			while (!s.empty() && s.top().first >= sum / cnt) {
				sum += s.top().first * s.top().second;
				cnt += s.top().second;
				s.pop();
			}
			s.push({sum / cnt, cnt - sum % cnt});
			if (sum % cnt != 0) s.push({sum / cnt + 1, sum % cnt});
		}
		ll mx = s.top().first;
		while (s.size() > 1) s.pop();
		cout << mx - s.top().first << '\n';

	}	
	return 0;
}