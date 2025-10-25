#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                ll n, m, a, b; cin >> n >> m >> a >> b;
                // try a, m
                ll one = 1;
                a = min(a, n - a + 1);
                b = min(b, m - b + 1);
                while (a > 1) {
                        a = (a + 1) / 2;
                        one++;
                }
                while (m > 1) {
                        m = (m + 1) / 2;
                        one++;
                }
                ll two = 1;
                while (b > 1) {
                        b = (b + 1) / 2;
                        two++;
                }
                while (n > 1) {
                        n = (n + 1) / 2;
                        two++;
                }
                cout << min(one, two) << '\n';
        }
}

