/*
 * pairs of (a_i, b_i) are inseparable.
 * this enforces some ordering on the pairs.
 * therefore, if the answer exists, it is unique.
 *
 * example:
 * 1, 2, 3, ..., (a - 1), ( values between a and z not utilized), etc.
 * a, b, c, ...,       z, 
 *
 * we know that:
 * we can swap two pairs without swapping (if n >= 3)
 * we can flip two pairs without swapping them
 * we cannot flip one pair on its own.
 *
 * therefore, we can have an even # of pairs out of order, and we can always orient the pairs properly as well.
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n; cin >> n;
                vector<int> a(n), b(n);
                for (int &x : a) cin >> x;
                for (int &x : b) cin >> x;

                vector<int> pos(2 * n + 1, 0);
                for (int i = 0; i < n; i++) {
                        pos[a[i]] = i;
                        pos[b[i]] = i;
                }

                int swaps = 0;
                set<int> s;
                for (int i = 1; i <= 2 * n; i++) {
                        s.insert(i);
                }
                bool works = true;
                bool oddswap = false;
                int pa = 0, pb = 0; // previous a and b values
                for (int i = 0; i < n; i++) {
                        // always pick element with the smallest value still available
                        int j = pos[*s.begin()];
                        int ca = a[j], cb = b[j];
                        s.erase(ca);
                        s.erase(cb);
                        if (pa < ca && pb < cb) {
                                pa = ca;
                                pb = cb;
                        } else {
                                swap(ca, cb);
                                swaps++;
                                if (pa < ca && pb < cb) {
                                        pa = ca; 
                                        pb = cb;
                                } else {
                                        works = false;
                                        break;
                                }
                        }
                        //cout << pa << " " << pb << '\n';
                        if ((i % 2 == 0) && (s.size() == 0 || *s.begin() == 2 * (i + 1) + 1)) {
                                //cout << "oddswap true\n";
                                oddswap = true;
                        }
                }

                //cout << works << " " << oddswap << " " << swaps << '\n';

                if (works && ((swaps % 2 == 0) || oddswap)) {
                        cout << "YES\n";
                } else {
                        cout << "NO\n";
                }

        }
}








