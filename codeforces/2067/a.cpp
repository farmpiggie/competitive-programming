/*
 * increases by 1 everytime for ones digit 0 -> 8
 * for an increase more than 1, we must have some # of 9s before the last 9.
 * 9 -> 10 (-8) (9 -> 1)
 * 99 -> 100 (-17) (18 -> 1)
 * 999 -> 1000 (-26) (27 -> 1)
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int x, y; cin >> x >> y;
                if (x + 1 == y) {
                        cout << "YES\n";
                } else {
                        int diff = (x - y);
                        if ((diff + 1) % 9 == 0 && diff > 0) { // amount shrinks
                                int z = (diff + 1) / 9;
                                if (x >= z * 9) {
                                        cout << "YES\n";
                                } else {
                                        cout << "NO\n";
                                }
                        } else {
                                cout << "NO\n";
                        }
                }
        }
}
                                


