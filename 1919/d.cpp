#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

int find(int a, vector<int>& par) {
	if (a == par[a]) return a;
	else return par[a] = find(par[a], par);
}

void merge(int a, int b, vector<int>& par, vector<int>& sz, vector<int>& mn, vector<int>& l, vector<int>& r) {
	a = find(a, par);
	b = find(b, par);
	if (a == b) return;
	if (sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	par[b] = a;
	mn[a] = min(mn[a], mn[b]);
	l[a] = min(l[a], l[b]);
	r[a] = max(r[a], r[b]);
}

void solve() {

	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> par(n), sz(n), mn(n), l(n), r(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		par[i] = i;
		sz[i] = 1;
		mn[i] = a[i];
		l[i] = i;
		r[i] = i;
	}

	// compare the two possible additions and make sure the biggest additions go first!
	auto cmp = [&mn, &par](pii a, pii b) {
		return max(mn[find(a.first, par)], mn[find(a.second, par)]) < max(mn[find(b.first, par)], mn[find(b.second, par)]);
	};

	priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);

	for (int i = 1; i < n; i++) {
		if (abs(a[i] - a[i - 1]) == 1) {
			// cout << "adding: " << i - 1 << ' ' << i << '\n';
			pq.push({i - 1, i});
		}
	}

	while (!pq.empty()) {
		pii p = pq.top(); pq.pop();
		// cout << "merging: " << p.first << " " << p.second << '\n';
		int n1 = find(p.first, par), n2 = find(p.second, par);
		if (n1 == n2) continue;
		if (abs(mn[n1] - mn[n2]) != 1) continue;
		merge(p.first, p.second, par, sz, mn, l, r);
		int node = find(p.first, par);
		int lft = l[node];
		int rgt = r[node];
		if (lft - 1 >= 0 && abs(mn[find(lft - 1, par)] - mn[node]) == 1) {
			pq.push({lft - 1, lft});
		} 
		if (rgt + 1 < n && abs(mn[find(rgt + 1, par)] - mn[node]) == 1) {
			pq.push({rgt, rgt + 1});
		}
	}


	if (sz[find(0, par)] == n && mn[find(0, par)] == 0) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}






}

int main() {
	int t; cin >> t;
	while (t--) solve();
	return 0;
}