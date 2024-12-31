/*
 * idea: back[i] = max(a[1...i])
 * so ans[i] = max(back[j]) for all j in [i, n - 1] s.t. a[j] < a[i]
 * iterate through indicies in order of height, query this?
 */

#include <bits/stdc++.h>
using namespace std;

struct dsu {
	vector<int> par, sz, mn, mx;
	
	dsu(int n, vector<int> a) {
		par = vector<int>(n);
		iota(par.begin(), par.end(), 0);
		sz = vector<int>(n, 1);
		mx = a; // copy this
		mn = a;
	}

	int find(int i) {
		if (i == par[i]) return i;
		else return par[i] = find(par[i]);
	}

	void merge(int i, int j) {
		i = find(i), j = find(j);
		if (i == j) return;
		if (sz[i] < sz[j]) swap(i, j);
		sz[i] += sz[j];
		par[j] = i;
		mx[i] = max(mx[i], mx[j]);
		mn[i] = min(mn[i], mn[j]);
	}

	int big(int i) {
		return mx[find(i)];
	}

	int small(int i) {
		return mn[find(i)];
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		dsu uf(n, a);

		vector<int> b;
		for (int i = n - 1; i >= 0; i--) {
			while (!b.empty() && uf.big(i) > uf.small(b.back())) {
			     	uf.merge(i, b.back());
			       	b.pop_back();
			}
			b.push_back(i);
		}

		for (int i = 0; i < n; i++) cout << uf.big(i) << " ";
		cout << '\n';
			
	}
	return 0;
}

