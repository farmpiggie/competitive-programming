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

#define pii pair<int, int>

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		map<int, int> mp;
		for (int& x : a) mp[x]++;
		vector<pii> b;
		for (auto& p : mp) b.push_back({p.first, p.second});
		sort(b.begin(), b.end());
		vector<int> lcms;
		ll cur = b[0].first;
		lcms.push_back(cur);
		for (int i = 1; i < (int) b.size(); i++) {
			cur = lcm(cur, b[i].first);
			lcms.push_back(cur);
		}
		reverse(lcms.begin(), lcms.end());
		reverse(b.begin(), b.end());
		vector<int> psum(b.size(), 0);
		int cnt = n;
		for (int i = 0; i < (int) b.size(); i++) {
			cout << lcms[i] << ' ';
			if (mp.find(lcms[i]) == mp.end()) { // lcm DNE
				break;
			} else {
				cnt -= b[i].second; // number of numbers with this
			}
		}
		cout << '\n';
		cout << cnt << '\n'; 
	}
}
