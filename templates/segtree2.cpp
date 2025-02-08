#include <bits/stdc++.h>
using namespace std;

struct segtree {
	int n;
	vector<int> t;

	segtree(int _n) {
		n = _n;
		t.resize(4 * n, 0);
	}

	int merge(int v1, int v2) {
		return gcd(v1, v2);
	}

	void update(int v, int l, int r, int p, int val) {
		if (l + 1 == r) {
			t[v] = val;
                        return;
		}
		int m = (l + r) / 2;
		if (p < m) update(v * 2 + 1, l, m, p, val);
		else update(v * 2 + 2, m, r, p, val);
	        t[v] = gcd(t[v * 2 + 1], t[v * 2 + 2]);
        }

        int query(int v, int l, int r, int L, int R) {
                if (L >= R) {
                        return 0;
                } 
                if (l == L && r == R) {
                        return t[v];
                } 
                int m = (l + r) / 2;
                return merge(query(v * 2 + 1, l, m, L, min(m, R)),
                             query(v * 2 + 2, m, r, max(m, L), R));
        }

        void update(int p, int val) {
                update(0, 0, n, p, val);
        }

        int query(int l, int r) {
                return query(0, 0, n, l, r);
        }
};

