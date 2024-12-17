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

int m, n;
vector<pii> x, y; // prod, con
vector<pii> prod, cons;

ll solve(int l, int r, int x, int y) {

	if (l > r || x > y) return 0;

	int lmid = (l + r) / 2;

	ll best = 0;
	int rmid = -1;
	for (int i = x; i <= y; i++) {
		// cout << "trying: (" << prod[lmid].f << ", " << prod[lmid].s << ")" << " and (" << cons[i].f << ", " << cons[i].s << ")\n";
		ll cur = 1ll * max(0, (cons[i].f - prod[lmid].f)) * max(0, (cons[i].s - prod[lmid].s));
		// cout << "value: " << cur << '\n';
		if (best < cur) {
			best = cur;
			rmid = i;
		}
	}
	
	if (rmid == -1) {
		rmid = x;
		while (rmid < y && cons[rmid].s < prod[lmid].s) ++rmid;
	} 
	return max(best, max(solve(l, lmid - 1, x, rmid), solve(lmid + 1, r, rmid, y)));
}

int main() {
	send help
	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		int price, day; cin >> price >> day;
		x.push_back({price, day});
	}

	for (int i = 0; i < n; i++) {
		int price, day; cin >> price >> day;
		y.push_back({price, day});
	}

	auto prod_cmp = [](const pii& a, const pii& b) {
		if (a.s != b.s) return a.s < b.s;
		else return a.f > b.f;
	};

	auto cons_cmp = [](const pii& a, const pii& b) {
		if (a.s != b.s) return a.s < b.s;
		else return a.f < b.f;
	};

	sort(x.begin(), x.end(), prod_cmp);
	sort(y.begin(), y.end(), cons_cmp);

	prod.push_back(x[0]);
	cons.push_back(y[n - 1]);

	for (int i = 1; i < m; i++) {
		if (prod.back().f <= x[i].f) continue;
		prod.push_back(x[i]);
	}

	for (int i = n - 2; i >= 0; i--) {
		if (cons.back().f >= y[i].f) continue;
		cons.push_back(y[i]);
	}

	reverse(cons.begin(), cons.end());

	cout << max(0ll, solve(0, prod.size() - 1, 0, cons.size() - 1)) << '\n';




	return 0;
}