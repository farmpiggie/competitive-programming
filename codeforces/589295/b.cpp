/*
 * given some number b,
 * count # of distinct lcm(a, b) for all a from 1 <= a <= 1e18.
 * decompose number b into prime factors (at most 11 prime factors)
 * max # of dinstinct factors in 1e18 is 13 distinct primes
 *
 * realize lcm(a, b) = # of factors containing both those in a and b,
 * so lcm(a, b) / a represents # of factors in b that are not in a.
 *
 * the # of factors in b that are not in A can simply be some combination of the factors in B.
 * so the # of unique values is simply the # of ways we can pick a distinct subset of primes.
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 1e5 + 5;

int main() {
        vector<int> primes, marked(MAXN, 0);
        for (int i = 2; i < MAXN; i++) {
                if (!marked[i]) {
                        primes.push_back(i);
                        for (int j = i; j < MAXN; j += i) {
                                marked[i] = 1;
                        }
                }
        }
        cin.tie(0)->sync_with_stdio(0);
        ll b; cin >> b;
        ll ans = 1;
        for (int prime : primes) {
                int cnt = 0;
                while (b % prime == 0) {
                        b /= prime;
                        cnt++;
                }
                ans *= (cnt + 1);
        }
        if (b > 1) ans *= 2;
        cout << ans << '\n';
}
                        

