/*
 * function rev(n, p):
 *      1. convert n (base 10) to base p
 *      2. reverse the base p number
 *      3. convert it back to n
 *
 * we want to sum rev(n, p) for p in [2, k]
 * note that for p in (n, INF), rev(n, p) = n.
 * note that for p in (sqrt(n), n], the length of n is two bits.
 *
 * we can brute force compute p for [2, sqrt(n)] in sqrt(n) * log(n) per test case
 * for (sqrt(n) to n], we can calculate the range of bases that c
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll MOD = 1e9 + 7;

ll _sqrt(ll x) {
        ll i = 1;
        while (i * i <= x) {
                i++;
        }
        return i - 1;
}

ll binpow(ll x, ll y) {
        if (y == 0) return 1;
        ll res = binpow(x, y / 2);
        res = res * res % MOD;
        if (y & 1) res = res * x % MOD;
        return res;
}

// sum from 1 to x
ll sum(ll x) {
        return x * (x + 1) % MOD / 2 % MOD;
}

// sum range from x to y inclusive
ll sum(ll x, ll y) {
        ll res = sum(y);
        if (x > 1) res = (res - sum(x - 1) + MOD) % MOD;
        return res;
}

// sum^2 range from 1 to x
ll sum2(ll x) {
        return x * (x + 1) % MOD * (2 * x + 1) % MOD / 6 % MOD;
}

// sum^2 range from x to y inclusive
ll sum2(ll x, ll y) {
        ll res = sum2(y);
        if (x > 1) res = (res - sum2(x - 1) + MOD) % MOD;
        return res;
}

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n;
                ll k; 
                cin >> n >> k;
                // convert base 10 number into base b
                auto convert = [&](int x, int b) -> vector<int> {
                        vector<int> ans;
                        while (x > 0) {
                                ans.push_back(x % b);
                                x /= b;
                        }
                        reverse(ans.begin(), ans.end());
                        return ans;
                };

                // convert base b number into base 10 number
                auto reconstruct = [&](vector<int> a, int b) -> ll {
                        ll ans = 0;
                        for (int i = 0; i < (int) a.size(); i++) {
                                ans = (ans + (1ll * a[i] * binpow(b, i) % MOD)) % MOD;
                        }
                        return ans;
                };

                // brute force from 2...sqrt(K)
                ll ans = 0;
                int K = min(k, sqrt(n));
                for (int i = 2; i <= K; i++) {
                        ans = (ans + reconstruct(convert(n, i), i)) % MOD;
                }
                // from sqrt(k) + 1 to n, we can calculate how many values will have some amount of numbers
                if (k > sqrt(n)) {
                        for (int msb = 1; msb < sqrt(n); msb++) {
                                // how many bases work with said msb?
                                // example: number 42
                                // msb of 1 with bases 22......42
                                // msb of 2 with bases 15......21
                                // binary search for biggest l s.t. n / l >= msb
                                int l = sqrt(n), r = min(n, k);
                                while (l < r) {
                                        int m = (l + r) / 2;
                                        if (n / m >= msb) {
                                                r = m; // try smaller
                                        } else {
                                                l = m + 1; // try bigger
                                        }
                                }
                                // binary search for same value but for msb + 1
                                int l2 = sqrt(n), r2 = min(n, k);
                                while (l2 < r2) {
                                        int m2 = (l2 + r2) / 2;
                                        if (n / m2 >= msb + 1) {
                                                r2 = m2;
                                        } else {
                                                l2 = m2 + 1;
                                        }
                                }
                                // range should now be [r2 + 1, r]
                                if (r2 + 1 > r) continue; // range not valid

                                // after reversing the string, we need to sum ones digits from (r2 + 1) to r at that position.
                                // so that will be msb at the lsb position
                                ll res = msb * (r - r2) % MOD;

                                // for the "ones" digit, we need to calculate what that value actually is
                                // break down each number into:
                                // d0, d1
                                // d0 = n / p
                                //
                                // d1 = n % p
                                // need to sum p * (n % p) and n / p.





        }
}




