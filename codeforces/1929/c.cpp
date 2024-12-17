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

ll k, x, a;

void solve() {
	cin >> k >> x >> a;
	ll negative = 0;
	bool works = true;

	for (int i = 0; i <= x; i++) {
		ll bet_size = negative / (k - 1) + 1;
		negative += bet_size;
		if (negative > a) {
			works = false;
			break;
		}
	}
	if (works) cout << "YES\n";
	else cout << "NO\n";
}

int t;

int main() {
	send help
	cin >> t;
	while (t--) solve();
	return 0;
}