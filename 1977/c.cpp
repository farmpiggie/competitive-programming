// find LCM of list
// note all possible LCMs of the array are factors of total LCM
// try all factors of 
#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

vector<ll> factors(ll n) {
	vector<ll> facs;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			facs.push_back(i);
			if (n / i != i) facs.push_back(n / i);
		}
	}
	return facs;
}

#define pii pair<int, int>

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<ll> a(n);
		for (ll& x : a) cin >> x;
		sort(a.begin(), a.end());
		set<ll> s;
		for (ll& x : a) s.insert(x);

		ll all_lcm = a[0];
		for (int i = 1; i < n; i++) {
			all_lcm = lcm(all_lcm, a[i]);
			if (all_lcm > (ll) 1e9+5) break;
		}
		if (all_lcm > a[n - 1]) {
			cout << n << '\n';
			continue;
		}

		int ans = 0;
		for (ll factor : factors(all_lcm)) {
			if (s.find(factor) != s.end()) continue;
			ll cur_lcm = -1;
			int cnt = 0;
			for (int i = 0; i < n; i++) {
				if (factor % a[i] == 0) {
					if (cur_lcm == -1) cur_lcm = a[i];
					else cur_lcm = lcm(cur_lcm, a[i]);
					cnt++;
				}
			}
			if (cur_lcm == factor) ans = max(ans, cnt); 
		}
		cout << ans << '\n';
	}
}
