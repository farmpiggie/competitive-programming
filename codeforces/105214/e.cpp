#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vl vector<ll> 
#define v2l vector<vl>

const ll MOD = 1e9 + 7;

struct Combo
{
	vector<ll> f = {1};
	vector<ll> in = {1};

	ll binpow (ll a, ll b = MOD - 2)
	{
		ll res = 1;
		while (b > 0)
		{
			if (b % 2)
			{
				res = res * a % MOD;
				b--;
			}
			a = a * a % MOD;
			b /= 2;
		}
		return res;
	}
	ll fact (int n)
	{
		while (f.size() <= n)
		{
			f.push_back(1ll * f.back() * (int)f.size() % MOD);	
		}
		return f[n];
	}

	ll inv (int n)
	{
		while (in.size() <= n)
		{
			in.push_back(1ll * in.back() * binpow(in.size()) % MOD);
		}
		return in[n];
	}
	
	ll choose (ll n, ll k)
	{
		return fact(n) * inv(k) % MOD * inv(n - k) % MOD;
	}
} c;

int main() {
	ll n, m, k; cin >> n >> m >> k;
	
	v2l dp(m + 1, vl(m + 1, 0));
	dp[0][0] = 1;
	
//	cout << "1\n";	
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= i; j++) {
			if (k - (j - 1) < 0) continue;
			if (i == 3 && j == 2) {
//				cout << dp[i - 1][j - 1] << " * " << (k - (j - 1)) << '\n';
//				cout << dp[i - 2][j - 1] << " * " << c.choose(i, 2) << " * " << (k - (j - 1)) << '\n';
			}
			dp[i][j] = (dp[i - 1][j - 1] * (k - (j - 1))) % MOD;  
			if (i - 2 >= 0) dp[i][j] = (dp[i][j] + dp[i - 2][j - 1] * (i - 1) % MOD * (k - (j - 1)) % MOD) % MOD;
		}
	}

/*	for (vl& x : dp) { 
		for (ll y : x) cout << y << " ";
		cout << '\n';	
	}
*/
	vl pw(m + 1, 0);
	
	ll ans = 0;
	ll sum = 0;
	for (int d = 1; d <= m; d++) {
//		cout << m << " " << d << " " << dp[m][d] << " " << c.binpow(k, n - m) << '\n';
		sum = (sum + dp[m][d]) % MOD;
	}

//	cout << ans << '\n';
//	cout << "2\n";


	for (int d = 0; d <= m; d++) {
		ll prod = 1;
		for (int w_len = 1; w_len <= m; w_len++) {
			if (k - d - w_len + 1 < 0) continue;
			prod = (prod * (k - d - w_len + 1)) % MOD;
			int x_len = m - 2 * w_len;
			if (x_len < 0) continue;

			if (k - d - w_len < 0) break;
			pw[w_len] = (pw[w_len] + dp[x_len][d] * prod % MOD) % MOD;
		}
	}

	for (int w_len = 1; w_len <= m; w_len++) sum = (sum - pw[w_len] + MOD) % MOD;	

	ans = (ans + sum * c.binpow(k, n - m) % MOD * (n - m + 1) % MOD) % MOD;

//	for (int i = 1; i <= m; i++) cout << pw[i] << " ";
//	cout << '\n';
//	cout << "3\n";
//	cout << ans << '\n';
//	cout << "----\n";
	for (int w_len = 1; w_len <= m; w_len++) {
		int cnt = w_len;
		int x_len = m - 2 * w_len;
		if (x_len < 0) break;
		int i = 1;
//		cout << cnt << '\n';
		while (cnt + x_len + w_len <= n) {
			cnt += x_len + w_len;
			if (n - cnt < 0) break;
//			cout << (pw[w_len] * i * c.binpow(k, n - cnt) % MOD * (n - cnt + 1) % MOD + MOD) % MOD << '\n'; 
			ans = (ans + pw[w_len] * i * c.binpow(k, n - cnt) % MOD * (n - cnt + 1) % MOD + MOD) % MOD;
			i *= -1;
//			cout << "cnt: " << cnt << '\n';
		}	
//		cout << ans << '\n';
	}

	cout << ans << '\n';

	return 0;
}
