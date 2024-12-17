#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll t, a, b, xk, yk, xq, yq;

bool hits(ll x1, ll y1, ll x2, ll y2) {
	return ((abs(x1 - x2) == a && abs(y1 - y2) == b) || (abs(x1 - x2) == b && abs(y1 - y2) == a));
}

void solve() {
	set<pll> s;
	cin >> a >> b >> xk >> yk >> xq >> yq;

	int count = 0;
	ll x, y;
	x = (xk - a), y = (yk - b);
	if (hits(x, y, xq, yq) && s.find(make_pair(x, y)) == s.end()) {
		s.insert(make_pair(x, y));
		count++;
	}
	x = (xk + a), y = (yk - b);
	if (hits(x, y, xq, yq) && s.find(make_pair(x, y)) == s.end()) {
		s.insert(make_pair(x, y));
		count++;
	}
	x = (xk - a), y = (yk + b);
	if (hits(x, y, xq, yq) && s.find(make_pair(x, y)) == s.end()) {
		s.insert(make_pair(x, y));
		count++;
	}
	x = (xk + a), y = (yk + b);
	if (hits(x, y, xq, yq) && s.find(make_pair(x, y)) == s.end()) {
		s.insert(make_pair(x, y));
		count++;
	}
	x = (xk - b), y = (yk - a);
	if (hits(x, y, xq, yq) && s.find(make_pair(x, y)) == s.end()) {
		s.insert(make_pair(x, y));
		count++;
	}
	x = (xk + b), y = (yk - a);
	if (hits(x, y, xq, yq) && s.find(make_pair(x, y)) == s.end()) {
		s.insert(make_pair(x, y));
		count++;
	}	
	x = (xk - b), y = (yk + a);
	if (hits(x, y, xq, yq) && s.find(make_pair(x, y)) == s.end()) {
		s.insert(make_pair(x, y));
		count++;
	}
	x = (xk + b), y = (yk + a);
	if (hits(x, y, xq, yq) && s.find(make_pair(x, y)) == s.end()) {
		s.insert(make_pair(x, y));
		count++;
	}

	// for (pll p : s) {
	// 	cout << p.first << ' ' << p.second << '\n';
	// }

	cout << count << '\n';

}



int main() {
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}