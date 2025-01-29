/*
 * idea: binary search for k
 * coordinate compress + use sweep line for y and bin search for x
 */
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct segtree {
        int n;
        vector<T> t;

        // utility to build
        void build() {
                for (int i = n - 1; i > 0; --i) {
                        t[i] = max(t[i<<1], t[i<<1|1]);
                }
        }

        segtree(int _n) {
                n = _n;
                t = vector<T>(2 * n + 2, 0);
        }

        /*segtree(int _n, vector<T>& init) {
                segtree(_n);
                for (int i = 0; i < (int) init.size(); i++) {
                        t[n + i] = init[i];
                }
                build();
        }
        */

        // sum on interval [l, r], care for posible overflow using INT
        T query(int l, int r) {
                r++;
                if (l > r) return 0;
                T res = 0;
                for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
                        if (l&1) res += t[l++];
                        if (r&1) res += t[--r];
                }
                return res;
        }

        // a[p] = value
        void set(int p, int value) {
                for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
        }

        // a[p] += value
        void add(int p, int value) {
                for (t[p += n] += value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
        }
};

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n; cin >> n;
                set<int> unique_x, unique_y;
                vector<array<int, 2>> pts(n);
                for (int i = 0; i < n; i++) {
                        cin >> pts[i][0] >> pts[i][1];
                        unique_x.insert(pts[i][0]);
                        unique_y.insert(pts[i][1]);
                }
                map<int, int> compress_x, compress_y;
                vector<int> uncompress_x, uncompress_y;
                int num_x = 0;
                for (int x : unique_x) {
                        compress_x[x] = num_x++;
                        uncompress_x.push_back(x);
                }
                int num_y = 0;
                for (int y : unique_y) {
                        compress_y[y] = num_y++;
                        uncompress_y.push_back(y);
                }
                for (int i = 0; i < n; i++) {
                        pts[i][0] = compress_x[pts[i][0]];
                        pts[i][1] = compress_y[pts[i][1]];
                }

                sort(pts.begin(), pts.end()); // sorted points from left to right.

                int low_k = 0, high_k = n / 4;
                int ans_k = 0;
                int ans_x = -1, ans_y = -1;
                while (low_k <= high_k) {
                        int cur_k = (low_k + high_k) / 2;

                        // sweepline over x_0, from left to right
                        segtree<int> lhs(num_y), rhs(num_y);
                        for (int i = 0; i < n; i++) {
                                rhs.add(pts[i][1], 1);
                        }

                        bool works = false; // dont worry about k = 0 case; if k = 0 is the answer, then any choice of x0, y0 will suffice.
                        int i = 0;
                        int x0 = 0, y0 = num_y - 1;
                        for (; x0 < num_x; x0++) {
                                while (i < n && pts[i][0] == x0) { // move from left to right
                                        lhs.add(pts[i][1], 1);
                                        rhs.add(pts[i][1], -1);
                                        i++;
                                }
                                // binary search for smallest y0 s.t. min(lhs.query(0, y0), rhs.query(0, y0)) >= k
                                int low_y = 0, high_y = num_y - 1;
                                y0 = num_y - 1;
                                while (low_y <= high_y) {
                                        int cur_y = (low_y + high_y) / 2;
                                        if (min(lhs.query(0, cur_y), rhs.query(0, cur_y)) >= cur_k) {
                                                y0 = min(y0, cur_y);
                                                high_y = cur_y - 1;
                                        } else {
                                                low_y = cur_y + 1;
                                        }
                                }
                                // check if works
                                if (min(lhs.query(0, y0), min(lhs.query(y0 + 1, num_y - 1), min(rhs.query(0, y0), rhs.query(y0 + 1, num_y - 1)))) >= cur_k) {
                                        works = true;
                                        break;
                                }
                        }
                        if (works) {
                                ans_x = x0 + 1, ans_y = y0 + 1;
                                ans_k = max(ans_k, cur_k);
                                low_k = cur_k + 1;
                        } else {
                                high_k = cur_k - 1;
                        }
                }
                cout << ans_k << '\n';
                if (ans_k == 0) {
                        cout << "0 0\n";
                } else {
                        cout << uncompress_x[ans_x] << ' ' << uncompress_y[ans_y] << '\n';
                }
        }
}

