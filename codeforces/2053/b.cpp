#include <bits/stdc++.h>
using namespace std;

struct segtree {
        int n;
        vector<int> t;

        segtree(int sz) {
                n = sz;
                t = vector<int>(2 * n);
                build();
        }

        segtree(int sz, const vector<int>& a) {
                n = sz;
                t = vector<int>(2 * n);
                for (int i = 0; i < n; i++) {
                        t[n + i] = a[i];
                }
                build();
        }

        void build() {
                for (int i = n - 1; i > 0; --i) {
                        t[i] = combine(t[i<<1], t[i<<1|1]);
                }
        }

        int combine(const int& a, const int& b) {
                return min(a, b); // TODO: change it based on what you need 
        }

        // = value for assignment, += value for increment
        void update(int p, const int& value) {
                for (t[p += n] += value; p > 1; p >>= 1) {
                        t[p>>1] = combine(t[p], t[p^1]);
                }
        }

        int query(int l, int r) {  // query on interval [l, r]
                r++;
                int resl = INT_MAX, resr = INT_MAX; // TODO: change it based on what you need
                for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
                        if (l & 1) resl = combine(resl, t[l++]);
                        if (r & 1) resr = combine(resr, t[--r]);
                }
                return combine(resl, resr);
        }

};



int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n; cin >> n;
                vector<int> l(n), r(n);
                for (int i = 0; i < n; i++) {
                        cin >> l[i] >> r[i];
                }
                
                segtree st(2 * n + 1);
                for (int i = 1; i < n; i++) {
                        if (l[i] == r[i]) {
                                st.update(l[i], 1);
                        }
                }
                
                cout << (st.query(l[0], r[0]) == 0);
                for (int i = 1; i < n; i++) {
                        if (l[i - 1] == r[i - 1]) {
                                st.update(l[i - 1], 1);
                        }
                        if (l[i] == r[i]) {
                                st.update(l[i], -1);
                        }
                        cout << (st.query(l[i], r[i]) == 0);
                }
                cout << '\n';
                
        }
}
