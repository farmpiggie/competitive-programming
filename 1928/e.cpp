#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> #
// using namespace __gnu_pbds;
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

int t, n, x, y, s;

#define MAXN 200005

ll len[MAXN] = {}, p[MAXN] = {};
map<ll, int> mp;

void solve() {
    cin >> n >> x >> y >> s;
    // cout << "NEW POP\n";

    // cout << n << " " << x << " " << y << " " << s << '\n';

    
    // cout << "boop" << '\n';

        // cout << flush;


    ll psum = 0;
    bool works = false;

    if (n == 1 && x == s) {
        cout << "YES\n";
        cout << x << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        psum += x + (i - 1) * y;
        ll target = s - psum;
        if (target < 1ll * (n - i) * (x % y)) break;
        // cout << "target: " << target << '\n';
            // cout << flush;

        // mod at index i first
        if ((target - 1ll * (n - i) * (x % y)) % y != 0) continue;
        ll required = (target - (n - i) * (x % y)) / y;
        // cout << "required: " << required << '\n';
            // cout << flush;

        if (len[required] <= (n - i)) { // working
            works = true;
            cout << "YES\n";
                        // cout << flush;

            ll val = x;
            for (int j = 0; j < i; j++) {
                cout << val << ' ';
                val += y;
            }
                                    // cout << flush;

            vector<int> print;
            // cout << (n - i) - len[required] << '\n';
            for (int j = 0; j < (n - i) - len[required]; j++) {
                print.push_back((x % y));
            }
            int cur = required;
            while (cur != 0) {
                // cout << "cur: " << cur << '\n';
                //                  
                int prv = p[cur];
                int diff = mp[cur - prv];
                // cout << cur << ' ' << prv << '\n';
                // cout << "diff: " << diff << '\n';
                for (int j = diff; j >= 0; j--) {
                    // cout << "adding: " << (x % y) + j * y << '\n';
                    print.push_back((x % y) + j * y);
                }
                cur = prv;
            }
            reverse(print.begin(), print.end());
            for (int val : print) cout << val << " ";
            cout << '\n';
             // cout << flush;
            return;

        }

    }
    if (!works) {
        cout << "NO\n";
    }


}

int main() {
	send help

    // cout << "boop" << '\n';

    for (ll i = 0; i < MAXN; i++) {
        mp[i * (i + 1) / 2] = i;
    }

    len[0] = 0;
    p[0] = -1;

    for (int i = 1; i < MAXN; i++) {
        len[i] = LLONG_MAX;
        p[i] = -1;
    }
    for (ll i = 1; i < MAXN; i++) {
        ll j = 1;
        while (j * (j + 1) / 2 <= i) {
            ll new_val = len[i - (j * (j + 1) / 2)] + (j + 1);
            if (new_val < len[i]) {
                len[i] = new_val;
                p[i] = i - (j * (j + 1) / 2);
            }
            j++;
        }
    }

    // cout << "xd" << '\n';

    cin >> t;
    while (t--) solve();
    

	return 0;
}