struct segtree {
	vector<ll> t;
	ll n;

	segtree(ll sz) {
		t = vector<ll>(2 * sz + 1, 0);
		n = sz;
	}

	void modify(ll p, ll value) {  // set value at position p
	  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
	}

	ll query(ll l, ll r) {  // sum on interval [l, r]
		r++;
		ll res = 0;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l&1) res += t[l++];
		    if (r&1) res += t[--r];
		}
		return res;
	}

};