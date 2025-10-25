/*
dp[i] = min cost to remove i....n - 1 given we completely remove a[i].
dp[i] = a[i] + min(max(0, a[i + 1] - i) + mn, sum(i + 1...n - 1) - (n - 1 + (i + 1) - 1));
mn = max(dp[j] + sum(i + 2....j - 1) - (j - 1 + (i - 2) + 1)) over all j >= i + 2
after we update dp[i], we set mn = min(mn + a[i + 1] - 1, dp[i + 1])
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n; cin >> n;
                vector<int> a(n);
                for (int &x : a) cin >> x;
                vector<ll> dp(n, 0);
                dp[n - 1] = a[n - 1];
                dp[n - 2] = a[n - 2] + max(0, a[n - 1] - (n - 1));
                ll mn = a[n - 1];
                ll sum = a[n - 1] - 1; // sum of all elements - # of elements, but for i + 2 onwards
                for (int i = n - 3; i >= 0; i--) {
                        /*
                        if (i == 1) {
                                cout << a[i] << " + " << max(0, a[i + 1] - (i + 1)) << " + min(" << mn << ", " << sum << ")\n";
                        }
                        */
                        dp[i] = a[i] + max(0, a[i + 1] - (i + 1)) + min(mn, sum);
                        mn = min(mn + a[i + 1] - 1, dp[i + 1]);
                        sum += a[i + 1] - 1;
                }
                /*
                for (int i = 0; i < n; i++) {
                        cout << dp[i] << ' ';
                }
                cout << '\n';
                */
                cout << dp[0] << '\n';
        }
}



