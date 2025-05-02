// given a ones and b twos, can we add make them zero?
// if we have odd # of 1s, answer is no
// if we have even # of ones, each pair of ones either contributes -2, 0, or 2
// if we have 2 or more ones, we can always make it work 
// otherwise, we cannot make it work
#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int a, b; cin >> a >> b;
                if (a & 1) {
                        cout << "NO\n";
                } else {
                        if ((a >= 2 || b % 2 == 0)) {
                                cout << "YES\n";
                        } else {
                                cout << "NO\n";
                        }
                }
        }
}
