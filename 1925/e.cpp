#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, ll>
#define MAXN 300005

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

int t, n, m, q, x[MAXN], v[MAXN];

ll calculate_sum(pii l, pii r) {
	ll x = l.first, y = r.first, value = l.second;
	return value * ((y - x - 1) * y - ((y - 1) * y / 2 - x * (x + 1) / 2));
}

ll calculate_sum(pii l, pii r, ll a, ll b) {
	if (a == l.first) a++;
	if (b == r.first) b--;
	ll x = l.first, y = r.first, value = l.second;
	return value * ((b - a + 1) * y - (b * (b + 1) / 2 - (a - 1) * a / 2));
}


void solve() {
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> v[i];
	}

	vector<pii> initial_harbors;
	set<pii> harbors;
	segtree st(n + 1); // values from 1 to n

	for (int i = 0; i < m; i++) {
		initial_harbors.push_back({x[i], 1ll * v[i]});
		harbors.insert({x[i], v[i]});
	}

	sort(initial_harbors.begin(), initial_harbors.end());

	// cout << "input read" << '\n';
	// init seg tree
	for (int i = 1; i < m; i++) {
		pii l = initial_harbors[i - 1], r = initial_harbors[i];
		st.modify(l.first, calculate_sum(l, r));
	}

	// cout << "seg tree initialized" << '\n';

	for (int i = 0; i < q; i++) {
		int a, b, c; cin >> a >> b >> c;
		// cout << "read in query " << i + 1 << "\n";
		// cout << a << " " << b << " " << c << '\n';
		if (a == 1) { // add harbor
			auto it = harbors.lower_bound({b, 0});
			auto it2 = --it; ++it;
			pii l = *it2, r = *it;
			// found left and right bounds
			// modify segment tree 
			st.modify(l.first, 0);
			pii new_harbor = {b, 1ll * c};
			st.modify(l.first, calculate_sum(l, new_harbor));
			st.modify(new_harbor.first, calculate_sum(new_harbor, r));
			harbors.insert(new_harbor);
		} else {
			// check endpoints of query to see which range they fall underneath
			auto it = harbors.lower_bound({b, 0}); // find a left boundary with (b, x)
			auto it2 = harbors.lower_bound({c, 0}); // find a right boundary with (c, x)
			// cout << "it: " << it->first << "  " << it->second << '\n';
			// cout << "i2: " << it2->first << "  " << it2->second << '\n';

			ll sum = 0;
			if (it == it2) { // simply within the same range
				--it; 
				// cout << "in the same range!" << '\n';
				// cout << "adding: " << calculate_sum(*it, *it2, b, c) << '\n';
				sum += calculate_sum(*it, *it2, b, c);
			} else { // not within the same range
				// find sum in middle
				// cout << "not in the same range!" << '\n';
				pii l = *it; // within (b, c)
				auto temp = --it2; ++it2;
				pii r = *(temp); // within (b, c)

				if (l.first != r.first) { // not the same harbor
					// cout << "finding middle sum..." << '\n';
					pii x_r = *(--temp);
					// cout << "adding: " << st.query(l.first, x_r.first) << '\n';
					sum += st.query(l.first, x_r.first);
				}

				// add the left and right ends
				// cout << "adding left: " << calculate_sum(*(--it), l, b, l.first - 1) << '\n';
				// cout << "adding right: " << calculate_sum(r, *(it2), r.first + 1, c) << '\n';
				sum += calculate_sum(*(--it), l, b, l.first - 1);
				sum += calculate_sum(r, *(it2), r.first + 1, c);
			}
			cout << sum << '\n';
		}
	}
}

int main() {
	t = 1;
	while (t--) solve();
	return 0;
}