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