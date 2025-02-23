/*
 * can we greedily pair biggest # in a with biggest # in b, and smallest in a with smallest in b.
 * then we can try any pair of a, b where it doesnt equal either one.
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n; cin >> n;
                map<int, int> a, b;
                int x;
                for (int i = 0; i < n; i++) {
                        cin >> x;
                        a[x]++;
                }
                for (int i = 0; i < n; i++) {
                        cin >> x;
                        b[x]++;
                }
                int small = a.begin()->first + b.begin()->first;
                int big = a.rbegin()->first + b.rbegin()->first;
                bool works = false;
                for (auto [x, _] : a) {
                        for (auto [y, _] : b) {
                                if (x + y != small && x + y != big) {
                                        works = true;
                                        break;
                                }
                        }
                }
                cout << (works ? "YES" : "NO") << '\n';
        }
}

