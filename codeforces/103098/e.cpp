#include <bits/stdc++.h>
using namespace std;
// each node in seg tree contains # of values, sum of even, sum of odd
#define ll long long
#define node array<ll, 3>

const ll MOD = 1e9 + 7;

map<int, int> compress;
map<int, int> uncompress;
struct segtree {
	int n;

	vector<node> t;
	segtree(int _n) {
		n = _n;
		t.resize(4 * n);	
	}

	// sz, even, odd
	node merge(node v1, node v2) {
		ll sz = v1[0] + v2[0];
		ll e = 0, o = 0;
		if (v1[0] & 1) {
			e = (v1[1] + v2[2]) % MOD;
			o = (v1[2] + v2[1]) % MOD;
		} else {
			e = (v1[1] + v2[1]) % MOD;
			o = (v1[2] + v2[2]) % MOD;
		}
		return {sz, e, o};
	}

	// vertex, left, right, position
	void update(int v, int l, int r, int p, int val) {
		if (l + 1 == r) { // leaf
			t[v][0] += val; // 1 or -1
			int even = (t[v][0] + 1) / 2;
			int odd = t[v][0] - even;
			t[v][1] = (1ll * uncompress[l] * even) % MOD;
			t[v][2] = (1ll * uncompress[l] * odd) % MOD;
			return;
		} 
		int m = (l + r) / 2;
		if (p < m) update(v * 2 + 1, l, m, p, val);
		else update(v * 2 + 2, m, r, p, val);
		// merge
		t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
	}

	node query(int v, int l, int r, int L, int R) {
		if (L >= R) return {0, 0, 0};
		if (l == L && r == R) {
			return t[v]; 
		}
		int m = (l + r) / 2;
		return merge(query(v * 2 + 1, l, m, L, min(m, R)),
			     query(v * 2 + 2, m, r, max(m, L), R));
	}

	void add(int idx) {
		update(0, 0, n, idx, 1);
	}

	void del(int idx) {
		update(0, 0, n, idx, -1);
	}

	ll query() {
		return query(0, 0, n, 0, n)[1]; // even sum
	}
};

int block_size = sqrt(50000); // sqrt(n)

struct query {
	int l, r, idx;

	bool operator<(query other) const {
		return make_pair(l / block_size, r) < make_pair(other.l / block_size, other.r);
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, q; cin >> n >> q;
	
	vector<int> a(n);
	set<int> unique;
	for (int& x : a) {
		cin >> x;
		unique.insert(x);
	}
	
	int num_unique = 0;
	for (int num : unique) {
		compress[num] = num_unique;
		uncompress[num_unique] = num;
		num_unique++;
	}

	for (int& x : a) {
		x = compress[x];
	}

	segtree st(num_unique);
	vector<ll> ans(q);
	vector<query> queries;
	for (int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		queries.push_back({l, r, i});
	}
	sort(queries.begin(), queries.end());

	int cur_l = 0, cur_r = -1;
	for (query q : queries) {
		while (cur_l > q.l) {
			cur_l--;
			st.add(a[cur_l]); 
		}
		while (cur_r < q.r) {
			cur_r++;
			st.add(a[cur_r]);
		}
		while (cur_l < q.l) {
			st.del(a[cur_l]);
			cur_l++;
		}
		while (cur_r > q.r) {
			st.del(a[cur_r]);
			cur_r--;
		}
		ans[q.idx] = st.query();
	}

	for (ll x : ans) cout << x << '\n';

};