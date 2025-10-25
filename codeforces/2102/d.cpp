#include <bits/stdc++.h>
using namespace std;

#define ll long long

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

        // = value for assignment, += value for increment
        void update(int p, const int& value) {
                for (t[p += n] = value; p > 1; p >>= 1) {
                        t[p>>1] = combine(t[p], t[p^1]);
                }
        }

        int query(int l, int r) {  // query on interval [l, r)
                int resl = 0, resr = 0; // TODO: change it based on what you need
                for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
                        if (l & 1) resl = combine(resl, t[l++]);
                        if (r & 1) resr = combine(resr, t[--r]);
                }
                return combine(resl, resr);
        }

        int combine(const int& a, const int& b) {
                return a + b; // TODO: change it based on what you need 
        }
};

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n; cin >> n;
                vector<int> a(n);
                for (int &x : a) cin >> x;
                
                auto inversions = [&]() {
                        segtree st(n + 1);
                        ll ans = 0;
                        for (int i = 0; i < n; i++) {
                                st.update(a[i], 1);
                                ans += st.query(0, a[i]);
                        }
                        return ans % 2;
                };

                int inversion_parity = inversions();

                vector<int> even, odd;
                for (int i = 0; i < n; i++) {
                        if (i % 2 == 0) {
                                even.push_back(a[i]);
                        } else {
                                odd.push_back(a[i]);
                        }
                }

                sort(even.rbegin(), even.rend());
                sort(odd.rbegin(), odd.rend());

                for (int i = 0; i < n - 3; i++) {
                        if (i % 2 == 0) {
                                a[i] = even.back();
                                even.pop_back();
                        } else {
                                a[i] = odd.back();
                                odd.pop_back();
                        }
                }

                if ((int) even.size() == 2) {
                        a[n - 2] = odd[0];
                        a[n - 3] = even[0];
                        a[n - 1] = even[1];
                } else {
                        a[n - 2] = even[0];
                        a[n - 3] = odd[0];
                        a[n - 1] = odd[1];
                }

                int try_parity = inversions();
                
                if (try_parity != inversion_parity) {
                        swap(a[n - 1], a[n - 3]);
                }

                for (int &x : a) cout << x << ' ';
                cout << '\n';
        }
}


