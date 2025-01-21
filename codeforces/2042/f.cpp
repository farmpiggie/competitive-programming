#include <bits/stdc++.h>
using namespace std;

#define ll long long
                                   //
const int K = 5; // 0...4
const ll INF = 1e18;

#define mat array<array<ll, K>, K> // 5x5 array
                                   

mat init(ll a, ll b) {
    mat c; 
    for (int i = 0; i < K; i++) {
        for (int j = 0; j <= i; j++) {
            c[j][i] = -INF;
        }
    }

    c[0][0] = c[2][2] = c[4][4] = 0; // no selection
    c[0][1] = c[2][3] = a + b; // left side
    c[0][2] = c[2][4] = a + b + b; // full segment
    c[1][1] = c[3][3] = a; // inside segment
    c[1][2] = c[3][4] = a + b; // right side
    return c;
}

mat merge(mat a, mat b) {
    mat c = init(-INF, -INF);
    for (int i = 0; i < K; i++) {
        for (int j = i; j < K; j++) {
            for (int k = j; k < K; k++) {
                c[i][k] = max(c[i][k], a[i][j] + b[j][k]);
            }
        }
    }
    return c;
}

vector<ll> a, b;

struct segtree {
    int n;
    vector<mat> t;

    segtree(int _n) {
        n = _n;
        t.resize(4 * n);
        build(0, 0, n);
    }

    // [l, r)
    void build(int v, int l, int r) {
        if (l + 1 == r) { // leaf
            t[v] = init(a[l], b[l]);
            return;
        }
        int m = (l + r) / 2;
        build(v * 2 + 1, l, m);
        build(v * 2 + 2, m, r);
        t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
    }

    // p is index to update
    void update(int v, int l, int r, int p) {
        if (l + 1 == r) {
            t[v] = init(a[l], b[l]);
            return;
        }
        int m = (l + r) / 2;
        if (p < m) update(v * 2 + 1, l, m, p);
        else update(v * 2 + 2, m, r, p);
        t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
    }

    // actual range is [L, R)
    mat query(int v, int l, int r, int L, int R) {
        if (L >= R) return init(-INF, -INF);
        if (l == L && r == R) return t[v];
        int m = (l + r) / 2;
        return merge(query(v * 2 + 1, l, m, L, min(m, R)),
                    query(v * 2 + 2, m, r, max(m, L), R));
    }

    void update(int p) {
        update(0, 0, n, p);
    }

    ll query(int l, int r) {
        return query(0, 0, n, l, r)[0][4];
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    a = vector<ll>(n);
    b = vector<ll>(n);
    for (ll& x : a) cin >> x;
    for (ll& x : b) cin >> x;

    segtree st(n);
    int q; cin >> q;
    while (q--) {
        int t, x , y; cin >> t >> x >> y;
        --x;
        if (t == 1) {
            a[x] = y;
            st.update(x); // update value at x.
        } else if (t == 2) {
            b[x] = y;
            st.update(x); // same update
        } else {
            cout << st.query(x, y) << '\n';
        }
    }
    return 0;
}


                                   

