// all numbers eventually become gcd(a[i])
// first reach a[i] the fastest way possible for any value?
//
// remove gcd(a[i]) from all numbers
// if we have 1s, answer = n - (# of ones)
//
// otherwise, we have some numbers.
// check if they are coprime
// if we have coprime numbers, then we can solve in n operations
// otherwise, takes n + 1
#include <bits/stdc++.h>
using namespace std;

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n; cin >> n;
                vector<int> a(n);
                for (int &x : a) cin >> x;

                int allgcd = a[0];
                for (int i = 0; i < n; i++) {
                        allgcd = gcd(allgcd, a[i]);
                }

                int ones = 0;

                for (int &x : a) {
                        x /= allgcd;
                        if (x == 1) ones++;
                }

                if (ones > 0) {
                        cout << n - ones << '\n';
                        continue;
                }

                bool coprime = false;
                for (int i = 0; i < n; i++) {
                        for (int j = i + 1; j < n; j++) {
                                if (gcd(a[i], a[j]) == 1) {
                                        coprime = true;
                                        break;
                                }
                        }
                }

                if (coprime) {
                        cout << n << '\n';
                        continue;
                }

                vector<int> dp(5005, 1e9);
                for (int i = 0; i < n; i++) dp[a[i]] = 0;

                for (int j = 5000; j >= 1; j--) {
                        for (int i = 0; i < n; i++) { // pick the gcd or don't pick the gcd
                                dp[gcd(a[i], j)] = min(dp[gcd(a[i], j)], dp[j] + 1);
                        }
                }

                cout << n + dp[1] - 1 << '\n';
        }
}


                
