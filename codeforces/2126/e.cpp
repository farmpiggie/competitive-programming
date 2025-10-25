#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n; cin >> n;
                vector<ll> p(n), s(n);
                for (ll &x : p) cin >> x;
                for (ll &x : s) cin >> x;

                if (n == 1) {
                        cout << (p[0] == s[0] ? "YES" : "NO") << '\n';
                        continue;
                }

                bool works = true;

                for (int i = 0; i < n; i++) {
                        ll cur;
                        if (i == 0) {
                                cur = p[i];
                                if (gcd(s[i + 1], cur) != s[i]) {
                                        works = false;
                                        break;
                                }
                        } else if (i == n - 1) {
                                cur = s[i];
                                if (gcd(p[i - 1], cur) != p[i]) {
                                        works = false;
                                        break;
                                }
                        } else {
                                cur = lcm(s[i], p[i]);
                                if (gcd(p[i - 1], cur) != p[i] || gcd(s[i + 1], cur) != s[i]) {
                                        works = false;
                                        break;
                                }
                        }
                }
                cout << (works ? "YES" : "NO") << '\n';
        }
}

