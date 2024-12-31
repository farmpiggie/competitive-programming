/*
* choosing row r decrements by (bsum * a[r])
* choosing col c decrements by (asum * b[c])
*
* find some r, c s.t.
* x = sum - (bsum * a[r]) - (asum * b[c]) + a[r] * b[c]
* x = asum * bsum - bsum * a[r] - asum * b[c] + a[r] * b[c]
* x = asum * (bsum - b[c]) + a[r] * (b[c] - bsum)
* x = (asum - a[r]) * (bsum - b[c])
* 
* iterate through divisors
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, q; cin >> n >> m >> q;
    ll asum = 0, bsum = 0;
    unordered_set<ll, custom_hash> a_set, b_set;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        asum += x;
        a_set.insert(x);
    }
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        bsum += x;
        b_set.insert(x);
    }

    while (q--) {
        ll x; cin >> x;
        bool works = false;
        for (ll i = 1; i * i <= abs(x); i++) {
            if (x % i != 0) continue;
            ll l = i, r = x / i; // asum - a[r] = l, bsum - b[c] = r
            if ((a_set.find(asum - l) != a_set.end() && b_set.find(bsum - r) != b_set.end()) || 
                (a_set.find(asum - r) != a_set.end() && b_set.find(bsum - l) != b_set.end()) ||
                (a_set.find(asum + l) != a_set.end() && b_set.find(bsum + r) != b_set.end()) || 
                (a_set.find(asum + r) != a_set.end() && b_set.find(bsum + l) != b_set.end())) {
                works = true;
                break;
            }
        }
        cout << (works ? "YES" : "NO") << '\n';
    }
    return 0;
}
        
        
