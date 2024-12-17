// find position within array, pre-calculate divisors

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

int t, n, x;

int main() {
	send help
    cin >> t;
    while (t--) {
        cin >> n >> x;
        // cout << "n, x: " << n << "\t" << x << '\n';
        int diff = (n - x);
        set<int> answer;
        int ans = 0;
        for (int i = 1; i <= sqrt(diff); i++) {
            if (diff % i == 0) {
                if (i % 2 == 0 && i / 2 + 1 >= x) {
                    answer.insert(i);
                }
                if (i == diff / i) continue;

                if ((diff / i) % 2 == 0 && (diff / i) / 2 + 1 >= x) {
                    answer.insert(diff / i);
                }
            }
        }
        diff = (n + (x - 2));
        for (int i = 1; i <= sqrt(diff); i++) {
            if (diff % i == 0) {
                if (i % 2 == 0 && i / 2 + 1 >= x) {
                    answer.insert(i);
                }
                if (i == diff / i) continue;

                if ((diff / i) % 2 == 0 && (diff / i) / 2 + 1 >= x) {
                    answer.insert(diff / i);
                }
            }
        }
        cout << answer.size() << '\n';
    }
	return 0;
}