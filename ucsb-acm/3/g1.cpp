/* easy version where k = 0
 * all a_i <= 1e7 can have factors of small primes up to 17 and 1 prime greater.
 * decompose each # into parity XOR for small primes and big prime
 * running map of {xor, list of big primes}
 * if we find a match, we need to start a new segment
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
        vector<int> primes = {2, 3, 5, 7, 9, 11, 13, 17};

        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n, k; cin >> n >> k;
                vector<int> a(n);
                for (int &x : a) cin >> x;
                
                vector<int> mask(n, 0), big(n, 1);
                for (int i = 0; i < n; i++) {
                        int x = a[i];
                        for (int j = 0; j < 8; j++) {
                                int parity = 0;
                                while (x % primes[j] == 0) {
                                        x /= primes[j];
                                        parity = 1 - parity;
                                }
                                mask[i] |= (parity << j);
                        }
                        big[i] = x; // remaining big prime (if it exists)
                }

                map<int, set<int>> mp; // mp[mask] = set of big primes
                int ans = 1;
                for (int i = 0; i < n; i++) {
                        if (mp.find(mask[i]) != mp.end() && mp[mask[i]].count(big[i])) {
                                ans++;
                                mp = {};
                        } 
                        mp[mask[i]].insert(big[i]);
                }
                cout << ans << '\n';
        }
}

