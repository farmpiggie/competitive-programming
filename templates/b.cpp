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

int main() {
	send help
    cin >> t;
    while (t--) {
        cin >> n;
        set<int> s;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            s.insert(x);
        }
        vector<int> a;
        for (int val : s) {
            a.push_back(val);
        }
        int idx = 0;
        int ans = 0;
        for (int i = 0; i < (int) a.size(); i++) {
            while (a[i] - a[idx] > n) {
                idx++;
            }
            ans = max(ans, i - idx + 1);
        }
        cout << ans << '\n';
    }
	return 0;
}