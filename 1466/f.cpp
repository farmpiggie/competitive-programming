#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

struct dsu {
    unordered_map<int, int, custom_hash> par, sz;

    void init(int x) {
        if (par.find(x) == par.end()) {
            par[x] = x;
            sz[x] = 1;
        }
    }

    int find(int x) {
        init(x);
        if (x == par[x]) return x;
        else return par[x] = find(par[x]);
    }

    void merge(int x, int y) {
        init(x); init(y);
        x = find(x), y = find(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        par[y] = x;
    }
};

ll binpow(ll a, ll b) {
    if (b == 0) return 1;
	ll res = binpow(a, b / 2);
	res = res * res % MOD;
	if (b % 2 == 1) res = res * a % MOD;
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m; cin >> n >> m;
	vector<array<int, 3>> edges;
	unordered_set<int, custom_hash> nodes;
					   
	ll s_p = 0, t = 1;
	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		if (k == 1) { // self loop
			int x; cin >> x;
			nodes.insert(x);
			nodes.insert(m + 1);
			edges.push_back({i + 1, x, m + 1});
		} else {
			int x, y; cin >> x >> y;
			nodes.insert(x);
			nodes.insert(y);
			edges.push_back({i + 1, x, y});
		}
	}

	dsu uf;
	vector<int> ans;
	for (auto [ind, x, y] : edges) {
		x = uf.find(x), y = uf.find(y);
		if (x == y) continue;
		uf.merge(x, y);
		ans.push_back(ind);	
		s_p++;
	}

	unordered_set<int, custom_hash> ccs;
	for (int node : nodes) ccs.insert(uf.find(node));

	for (int cc : ccs) {
		t = t * binpow(2, uf.sz[cc] - 1) % MOD;
	}

	sort(ans.begin(), ans.end());
	cout << t << " " << s_p << '\n';
	for (int x : ans) cout << x << " ";
	cout << '\n';
	return 0;
}
