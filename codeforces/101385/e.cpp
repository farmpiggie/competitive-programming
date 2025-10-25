#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vl vector<ll>
#define v2l vector<vl>

const ll MOD = 1e9 + 7;

int main() {
    ifstream cin("jumping.in");
    ofstream cout("jumping.out");
    ll a, b; cin >> a >> b;
    int n = (b - a + 1);
    // dp[i][0/1] = # of ways to move to i given rita/pasha's turn was executed last 
    v2l dp(n, vl(2, 0));
    vl psum0(n, 0); // psum[i] = sum(dp[k][0])
    vl small(n, 0), big(n, 0);
    dp[0][1] = 1;

    vector<array<ll, 3>> arr; // endpt of segment, index it belongs to, start or end
    for (ll i = a; i <= b; i++) {
        for (ll j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                small[i - a] = j;
                big[i - a] = i / j;
                arr.push_back({(i - a) + j, i - a, 0});
                arr.push_back({(i - a) + (i / j) + 1, i - a, 1}); // exclusive end here.
                break;
            }
        }
    }
    sort(arr.begin(), arr.end());

    ll sum1 = 0; // sum0 = sum of active dp states ending in 0, sum1 = sum of active dp states ending in 1
    // first range can only start from (i + 2), so both these values should be zero at least for the first iteration. LOL

    // dp[i][0] = sum(dp[k][1]) for all k <=  
    // dp[i][1] = 
    int k = 0;
    for (int i = 1; i < n; i++) {
        while (k < arr.size() && arr[k][0] <= i) {
            if (arr[k][2] == 0) { // start
                sum1 = (sum1 + dp[arr[k][1]][1]) % MOD;
            } else { // end
                sum1 = (sum1 - dp[arr[k][1]][1] + MOD) % MOD;
            }
            k++;
        }
        dp[i][0] = sum1;

        // pasha can't jump to a prime number.
        // cout << "range for " << i + a << " goes back to: [" << i + a - big[i] << ", " << i + a - small[i] << "]\n";
        if (small[i] != 0 && i - small[i] >= 0) 
            dp[i][1] = (psum0[i - small[i]] 
                     - (i - big[i] - 1 >= 0 ? psum0[i - big[i] - 1] : 0) 
                     + MOD) % MOD;
        psum0[i] = (psum0[i - 1] + dp[i][0]) % MOD;
    }

    // for (int i = 0; i < n; i++) cout << dp[i][0] << " ";
    // cout << '\n';
    // for (int i = 0; i < n; i++) cout << dp[i][1] << " ";
    // cout << '\n';
    cout << (dp[n - 1][0] + dp[n - 1][1]) % MOD << '\n';

    return 0;
}