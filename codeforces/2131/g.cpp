#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

// f(x) = mult of x.

vector<ll> f(33), sum(33);

int main() {
        f[1] = 1;
        for (int i = 2; i < f.size(); i++) {
                f[i] = i;
                for (int j = 1; j < i; j++) {
                        f[i] = f[i] * f[j] % MOD;
                }
        }
        sum[0] = 1;
        sum[1] = 1;
        for (int i = 2; i < sum.size(); i++) {
                sum[i] = sum[i - 1] * f[i] % MOD;
        }

        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n, k; cin >> n >> k;
                vector<int> a(n);
                for (int &x : a) cin >> x;
                sort(a.rbegin(), a.rend());

                ll ans = 1;
                while (k > 0) { // guaranteed set isnt empty before operations are complete
                        int x = a.back();
                        a.pop_back();
                        ans = ans * x % MOD;
                        k--;
                        // creating 1....(x - 1)
                        while (k > 0) {
                                int y = 1;
                                while ((1ll << y) - 1 <= k && y <= x - 1) {
                                        y++;
                                }
                                y--;
                                ans = ans * sum[y] % MOD;
                                k -= (1ll << y) - 1;
                                if (y == x - 1) break;
                                if (k > 0) {
                                        ans = ans * (y + 1) % MOD; // the leftover
                                        x = y + 1;
                                        k--;
                                }
                        }
                }
                cout << ans << '\n';
        }
}





                        

