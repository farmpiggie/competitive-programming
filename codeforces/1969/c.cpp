// stop when all elements are homogenous
// if k = 1, simply choose largest gap
// if required to choose a particular element, choose smaller of two numbers always
// ex. 100 2 1, if k = 1 we choose 100 to 2
#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct dsu {
	vector<ll> par, sz, mn;
	
	dsu(int n, vector<ll>& arr) {
		par = vector<ll>(n);
		sz = vector<ll>(n);
		mn = vector<ll>(n);
		for (int i = 0; i < n; i++) {
			par[i] = i;
			sz[i] = 1;
			mn[i] = arr[i];
		}
	}

	int find(int a) {
		if (a == par[a]) return a;
		else return par[a] = find(par[a]);
	}

	void merge(int a, int b) {
		a = find(a); b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b];
		mn[a] = min(mn[a], mn[b]);
		par[b] = a;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		vector<ll> a(n);
		ll sum = 0;
		for (ll& x : a) {
			cin >> x;
			sum += x;
		}
		dsu uf(n, a);
		ll sum_benefit = 0;
		while (k--) {
			ll best = 0;
			vector<int> merge_candidates;
			for (int i = 1; i < n; i++) {
				int a = uf.find(i - 1), b = uf.find(i); // connected components
				if (a != b)  {
					ll benefit;
					if (uf.mn[a] > uf.mn[b]) swap(a, b); // a costs less
					benefit = 1ll * (uf.mn[b] - uf.mn[a]) * uf.sz[b];
					if (benefit > best) {
						merge_candidates = {i};
						best = benefit;
					} else if (benefit == best) {
						merge_candidates.push_back(i);
					}
				}
			}
			if (merge_candidates.size() != 0) {

				cout << merger << '\n';
				uf.merge(merger - 1, merger);
				sum_benefit += best;
			}
		}
		cout << sum - sum_benefit << '\n';
	}
	return 0;
}
