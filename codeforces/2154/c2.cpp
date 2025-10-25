#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAX = 2e5 + 5;
int main() {
        vector<vector<int>> prime_factors(MAX);
        for (int i = 2; i < MAX; i++) {
                if (!prime_factors[i].empty()) continue;
                for (int j = i; j < MAX; j += i) {
                        prime_factors[j].push_back(i);
                }
        }

        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n; cin >> n;
                vector<ll> a(n), b(n);
                vector<int> ord(n);
                iota(ord.begin(), ord.end(), 0);
                for (ll &x : a) cin >> x;
                for (ll &x : b) cin >> x;
                sort(ord.begin(), ord.end(), [&](int i, int j) -> bool {
                        return b[i] < b[j];
                });


                ll ans = b[ord[0]] + b[ord[1]];
                map<int, int> cnt;
                for (int i = 0; i < n; i++) {
                        for (int p : prime_factors[a[i]]) {
                                cnt[p]++;
                                if (cnt[p] > 1) ans = 0;
                        }
                }

                // a[i] and a[i + 1] are coprime, no need to subtract
                for (int i = 0; i < n; i++) {
                        for (int p : prime_factors[a[i] + 1]) {
                                if (cnt[p] > 0) {
                                        ans = min(ans, b[i]);
                                }
                        }
                }

                int idx = ord[0];
                set<int> s;
                for (int i = 0; i < n; i++) {
                        if (i == idx) continue;
                        for (int p : prime_factors[a[i]]) {
                                s.insert(p);
                        }
                }

                for (int p : s) {
                        ans = min(ans, 1ll * b[idx] * ((p - (a[idx] % p)) % p));
                }

                cout << ans << '\n';
        }
}

