#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define f first
#define s second

struct dsu {
	vector<int> par, sz;

	dsu(int n) {
		par = vector<int>(n + 1);
		sz = vector<int>(n + 1);

		for (int i = 0; i <= n; i++) {
			par[i] = i;
			sz[i] = 1;
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
		par[b] = a;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<vector<vector<pii>>> offsets(11, vector<vector<pii>>(10, vector<pii>(0)));
		for (int i = 0; i < m; i++) {
			int a, d, k; cin >> a >> d >> k;
			offsets[d][a % d].push_back({a, a + d * k});
		}
		for (int i = 1; i <= 10; i++) {
			for (int j = 0; j < 10; j++) {
				sort(offsets[i][j].begin(), offsets[i][j].end());
			}
		}

		dsu uf(n + 1);

		for (int i = 1; i <= 10; i++) { // jump
			for (int j = 0; j < i; j++) { // offset
				vector<pii>& segments = offsets[i][j];
				int end = -1;
				int idx = 0;
				for (int k = j; k <= n; k += i) {
					// find all segments that start before or at i, find longest range
					while (idx < segments.size() && segments[idx].f <= k) {
						end = max(end, segments[idx].s);
						idx++;
					}
					if (k + i <= end) {
						uf.merge(k, k + i);
					}
				}
			}		
		}

		set<int> groups;
		for (int i = 1; i <= n; i++) {
			groups.insert(uf.find(i));
		}
		cout << groups.size() << endl;
	}
	return 0;
}