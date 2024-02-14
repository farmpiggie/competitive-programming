#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> #
using namespace __gnu_pbds;
using namespace std;

#define send ios::sync_with_stdio(false);
#define help cin.tie(NULL);
#define f first
#define s second
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

#define MAXN 200005

int t, n;
ll b, x, c[MAXN];
ll cnt[MAXN];
ll add[MAXN]; // for values that are less than cnt[i]

void solve() {
    cin >> n >> b >> x;

    ll max_ci = 0;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        max_ci = max(max_ci, c[i]);
    }

    vector<ll> cnt(max_ci + 1, 0);
    vector<ll> add(max_ci + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int k = 1; k <= c[i]; k++) {
            ll small = (k - (c[i] % k));
            ll big = c[i] % k;
            ll small_size = c[i] / k;
            ll big_size = c[i] / k + 1;
            ll math = b * (c[i] * c[i] - small * small_size * small_size - big * big_size * big_size) / 2;
            // cout << b << " " << c[i] << " " << k << " " << math << '\n'; 

            cnt[k] += math;
            if (k == c[i]) {
                add[k] += math;
            }
        }
    }

    ll sum = 0;
    ll best = 0;
    for (int k = 1; k <= max_ci; k++) {
        best = max(best, cnt[k] + sum - x * (k - 1));
        sum += add[k];
    }
    cout << best << '\n';

}


int main() {
	send help
    cin >> t;
    while (t--) solve();
	return 0;
}