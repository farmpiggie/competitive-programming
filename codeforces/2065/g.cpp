#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 2e5 + 5;

int main() {
        // primes up to 2e5
        set<int> primes;
        vector<bool> notprime(MAXN, 0);
        for (int i = 2; i < MAXN; i++) {
                if (!notprime[i]) {
                        primes.insert(i);
                        for (int j = 2 * i; j < MAXN; j += i) {
                                notprime[j] = 1;
                        }
                }
        }

        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n; cin >> n;
                vector<int> a(n);
                for (int &x : a) cin >> x;

                ll ans = 0;
                ll prime_cnt = 0;
                map<int, int> prime_occ; // mp[prime] = occ
                map<int, int> prime_to_semiprime; // mp[prime] = semiprime count
                map<int, int> semiprime_occ; // mp[semiprime] = occ
                                             
                for (int i = 0; i < n; i++) {
                        if (primes.count(a[i])) {
                                prime_occ[a[i]]++;
                                prime_cnt++;
                        } else {
                                vector<int> fac;
                                for (int j = 2; j * j <= a[i]; j++) {
                                        if (a[i] % j == 0) {
                                                fac.push_back(j);
                                                fac.push_back(a[i] / j);
                                        }
                                }
                                if (fac.size() == 2 && primes.count(fac[0]) && primes.count(fac[1])) {
                                        semiprime_occ[a[i]]++;
                                        prime_to_semiprime[fac[0]]++;
                                        if (fac[0] != fac[1]) { //cant match 7 to 49 twice.
                                                prime_to_semiprime[fac[1]]++;
                                        }
                                }
                        }
                }

                // match every prime to prime that is not the same as itself
                for (auto [prime, cnt] : prime_occ) {
                        ans += 1ll * cnt * (prime_cnt - cnt);
                }
                ans /= 2; // overcount
                
                          
                for (auto [prime, cnt] : prime_occ) {
                        if (prime_to_semiprime.find(prime) == prime_to_semiprime.end()) continue;
                        ans += 1ll * cnt * prime_to_semiprime[prime]; // match each version of said prime to a matching semiprime
                }
                for (auto [semiprime, cnt] : semiprime_occ) {
                        ans += 1ll * cnt * (cnt + 1) / 2; // match semiprime to every copy (including itself)
                }

                cout << ans << '\n';
        }
}


