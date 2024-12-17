#include <bits/stdc++.h>
using namespace std;

// given n urinals, k people s.t. k <= n/2, return # of valid urinal combinations
// dp[i][j] = given i people and j urinals, return # of valid urinal combinations using j urinals s.t. we end with a urinal at j
// dont overcount urinals by only using combos 
// dp[i][j] = dp[i - 1][l] for 0 <= l <= (j - 2)
// use psum[j] to calculate sum of dp[i - 1][l] from 0 <= l <= j


const int MAXN = 1e3 + 5;
int t, n, k, dp[MAXN][MAXN] = {{0}}, psum[MAXN];

void solve() {
    cin >> n >> k;

    for (int j = 1; j <= n; j++) 
    	dp[1][j] = 1;

    psum[1] = dp[1][1];

    for (int j = 2; j <= n; j++)
    	psum[j] = psum[j - 1] + dp[1][j];

    for (int i = 2; i <= k; i++) {
    	for (int j = 2 * i; j <= n; j++) {
    		dp[i][j] = psum[j - 2];
    	}
    	psum[1] = dp[i][1];
    	for (int j = 2; j <= n; j++) psum[j] = psum[j - 1] + dp[i][j];
    }

    int ans = 1;
    for (int i = 1; i <= k; i++) {
    	for (int j = 0; j <= n; j++) {
    		ans += dp[i][j];
    	}
    }
    cout << ans << endl;



}

int main() {
    cin >> t;
    while (t--) solve();
    return 0;
}