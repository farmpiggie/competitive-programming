/* directed edge from i to j if i < j and gcd(a[i], a[j]) != 1
dp[i] = # of paths from node 1 to i

simple n^2: 
dp[i] = sum(dp[j]) s.t. gcd(a[i], a[j]) != 1
store sum[i] = sum(dp[j]) s.t. i divides a[j].
we can use inclusion/exclusion to calculate dp[i] over all prime factors of a[i].

*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAXN = 1e6 + 5;

int main() {
	// calculate sieve
	vector<int> sieve(MAXN, 0);
	vector<int> primes;
	for (int i = 2; i < MAXN; i++) {
		if (sieve[i] != 0) continue;
		sieve[i] = i;
		primes.push_back(i);
		for (int j = 2 * i; j < MAXN; j += i) {
			if (sieve[j] != 0) continue;
			sieve[j] = i;
		}
	}

	auto get_primes = [&](int x) -> vector<int> {
		set<int> s;
		while (x > 1) {
			s.insert(sieve[x]);
			x /= sieve[x];
		}
		vector<int> ret;
		for (int val : s) ret.push_back(val);
		return ret; 	
	};

	auto factors = [&](int x) -> vector<int> {
		vector<int> ans;
		for (int i = 1; i <= sqrt(x); i++) {
			if (x % i == 0) {
				ans.push_back(i);
				if (x / i != i) ans.push_back(x / i);
			}
		}
		return ans;
	};

	int n; cin >> n;
	vector<int> a(n); 
	for (int& x : a) cin >> x;

	vector<int> dp(n, 0);
	vector<int> sum(MAXN, 0);

	// inclusion exclusion
	auto calc = [&](vector<int> v) -> int {
		int ans = 0;
		for (int i = 1; i < (1 << (int) v.size()); i++) {
			int cur = 1;
			for (int j = 0; j < (int) v.size(); j++) {
				if ((i >> j) & 1) cur *= v[j];
			}
			if (__builtin_popcount(i) % 2 == 0) ans = (ans + MOD - sum[cur]) % MOD;
			else ans = (ans + sum[cur]) % MOD; 
		}
		return ans;
	};

	dp[0] = 1;
	for (int j : factors(a[0])) sum[j] = 1;
	
	for (int i = 1; i < n; i++) {
		dp[i] = calc(get_primes(a[i]));
		for (int j : factors(a[i])) {
			sum[j] = (sum[j] + dp[i]) % MOD;
		}
	}
	cout << dp[n - 1] << '\n';	

			
	return 0;
}
