/* parity of k and n must be the same
 * smallest number we can represent with k distinct positive odd numbers:
 * (1 + 3 + ... + (2 * k - 1))
 * = k^2
 * we can represent all k^2 + 2x
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                ll n, k; cin >> n >> k;
                ll diff = n - k * k;
                if (diff >= 0 && diff % 2 == 0) cout << "YES\n";
                else cout << "NO\n";
        }
}
