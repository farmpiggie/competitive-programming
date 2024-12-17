/*

card of suit 1 can beat any card NOT of suit 1
if cards are same suit, higher rank beats.
otherwise the cards cannot beat each other.

you must get x >= m / 2 cards of suit 1
only cards of suit 1 can beat cards of suit 1.
you will have 2 * (x - m / 2) cards of suit 1 left over.

1. how many ways to choose cards of suit 1?

dp[i][j] = # of ways to consider cards 1...i having chosen j cards.
what are our cases?
a. we don't take the card (condition on we have extras from previous states)
	if (2 * j - (i - 1) > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
b. we take the card (we always can do this)
	dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;

dp[0][0] = 1 (we can always choose no cards starting from 0)

# of ways to choose j cards considering 1...m should be dp[m][j]

2. how many ways to choose cards of other suits consider k wildcards?
ok. so given each rank now, we can apply the same logic from the table. 
however, we need to keep track of # of ways to choose x cards if x < m / 2. 
in this case, can we modify our dp to also keep track of the # of cards we use extra of?

dp2[i][j][k] = # of ways to choose which satisfies ranks 1...i, having chosen j cards, with k wildcards taken.
# of extra values = 2 * (j + k) - i
what are our cases?
a. we don't take the card (conditioned on we have extras from previous state)
	if (2 * (j + k) - (i - 1) > 0) dp2[i][j][k] += dp2[i - 1][j][k];
b. we do take the card
	dp2[i][j][k] += dp2[i - 1][j - 1][k];
c. we take a wildcard instead
	dp2[i][j][k] += dp2[i][j][k - 1];

# of ways we can choose any suit != 1 with k wildcards used is:
dp2[m][m / 2 - k][]

starting state: dp[0][0][0] = 1;


so we know that for each value of x, we will have this many groups.
however, each group also has some # of possibilities?
we can use dp

dp3[i][j] = # of ways to distribute groups 1...n given we have used j wildcards.
dp3[1][0] = 1;
dp3[i][j] = sum(dp3[i - 1][j - k] * dp2[n][m / 2 - k][k]) for all k >= j 

so our answer is sum(sum(dp[i][x] for all i) * dp3[n][x - m / 2]) for all x >= m / 2!!!

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vl vector<ll>
#define v2l vector<vl>
#define v3l vector<v2l>

const ll MOD = 998244353;

int n, m;

bool inrange(int i, int j, int k) {
	return i >= 0 && i <= m && j >= 0 && j <= m && k >= 0 && k <= m;
}

int main() {
	cin >> n >> m;

	v2l dp(m + 1, vl(m + 1, 0));
	dp[0][0] = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= m; j++) {
			if (i - 1 >= 0 && 2 * j - (i - 1) > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
			if (i - 1 >= 0 && j - 1 >= 0) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
		}
	}

	if (n == 1) {
		cout << dp[m][m / 2] << '\n';
		return 0;
	}

	v3l dp2(m + 1, v2l(m + 1, vl(m + 1, 0)));
	dp2[0][0][0] = 1; // not taking the first card is valid.
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= m; j++) {
			for (int k = 0; k <= m; k++) {
				if (inrange(i - 1, j, k) && 2 * (j + k) - (i - 1) > 0) dp2[i][j][k] = (dp2[i][j][k] + dp2[i - 1][j][k]) % MOD;
				if (inrange(i - 1, j - 1, k)) dp2[i][j][k] = (dp2[i][j][k] + dp2[i - 1][j - 1][k]) % MOD;
				if (inrange(i, j, k - 1)) dp2[i][j][k] = (dp2[i][j][k] + dp2[i][j][k - 1]) % MOD;
				// if (inrange(i - 1, j - 1, k) && i - 1 > 0) dp2[i][j][k] = (dp2[i][j][k] + dp2[i - 1][j - 1][k]) % MOD; // take next element
				// if (inrange(i - 2, j - 1, k) && i - 2 > 0) dp2[i][j][k] = (dp2[i][j][k] + dp2[i - 2][j - 1][k]) % MOD; // take 2nd next element
				// if (inrange(i - 1, j, k - 1)) dp2[i][j][k] = (dp2[i][j][k] + dp2[i - 1][j][k - 1]) % MOD; // take this element as a "wildcard"
				// if (inrange(i - 2, j, k - 1)) dp2[i][j][k] = (dp2[i][j][k] + dp2[i - 2][j][k - 1]) % MOD; // take this element as a "wildcard"
			}
		}
	}

	v2l dp3(n + 1, vl(m + 1, 0));
	// for (int i = 0; i <= m; i++) dp3[1][i] = dp[m][i]; // # of ways to consider 1..m and choose i of them.
	// cout << "sum1: ";
	// for (int i = 0; i <= m; i++) cout << sum1[i] << ' ';
	// cout << '\n';
	// dp3[i][j] = # of ways to choose groups 2...i such that we have used j wildcards.
	dp3[1][0] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			for (int k = 0; k <= j; k++) {
				if (i == 2 && j == 2) {
					cout << "evaluating dp3[" << i << "][" << j << "]\n";
					cout << "considering dp3[" << i - 1 << "][" << j - k << "] * dp2[" << m << "][" << m / 2 - k << "][" << k << "]: ";
					cout << '\n';
					cout << dp3[i - 1][j - k] << " " << dp2[m][m / 2 - k][k] << '\n'; 
				}
				// if we take use exactly k wildcards on this entry, what do we get?
				// cout << i << " " << j << " " << k << '\n';
				// cout << dp3[i - 1][j - k] << " " << dp2[n][m / 2 - k][k] << '\n';
				// if we take k wildcards, we need to take (m / 2 - k entries)
				//if (m / 2 - k >= 0) 
				dp3[i][j] = (dp3[i][j] + ((dp3[i - 1][j - k] * dp2[m][max(0, m / 2 - k)][k]) % MOD)) % MOD; 
				//else dp3[i][j] = (dp3[i][j] + dp3[i - 1][j - k]) % MOD; // nothing taken, one entry.
			}
		}
	}

	ll ans = 0;
	for (int x = m / 2; x <= m; x++) {
		// failing to consider case with 0 wildcards.
		cout << "considering dp[" << m << "][" << x << "] * dp3[" << n << "][" << 2 * (x - m / 2) << "]: ";

		cout << dp[m][x] << " " << dp3[n][2 * (x - m / 2)] << '\n';
		// ans = ans + ((sum1[x] * dp3[n][2 * (x - m / 2)]) % MOD) % MOD;
		ans = (ans + ((dp[m][x] * dp3[n][2 * (x - m / 2)]) % MOD)) % MOD; 
	}

	cout << ans << '\n';



	return 0;
}