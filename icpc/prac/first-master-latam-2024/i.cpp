#include <bits/stdc++.h>
using namespace std;

 
typedef long long ll;
const ll p = 31;
const ll m = 1e9+9;

vector<long long> p_pow;

vector<ll> prefix_hash(string const& s) {
	int S = s.length();
    vector<long long> h(S + 1, 0); 
    for (int i = 0; i < S; i++)
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
	return h;
}

ll string_hash(vector<ll>& h, int start, int end) {
	start++;
	end++;
    return (h[end] + m - h[start - 1]) % m;
}
	
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vector<string> a(n);
	for (string& s : a) cin >> s;
	string s; cin >> s;

	p_pow.resize(1e6 + 5);
	p_pow[0] = 1;
	
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

	vector<ll> pre = prefix_hash(s);
	vector<vector<ll>> prefix_hashes(n, vector<ll>(0));

	for (int i = 0; i < n; i++) {
		prefix_hashes[i] = prefix_hash(a[i]);
	}

	vector<int> dp((int) s.length(), 0);

	for (int i = 0; i < n; i++) {
		int len = a[i].length();
		for (int j = 1; j <= min(len, (int) s.length()); j++) {	
			ll s_hash = (string_hash(pre, 0, j - 1) * p_pow[len - j]) % m;
			ll a_hash = string_hash(prefix_hashes[i], len - j, len - 1);
			
			if (s_hash == a_hash) {
				dp[j - 1] = 1;
			}
		}
	}

	for (int i = 0; i < (int) s.length(); i++) {
		for (int j = 0; j < n; j++) {
			int len = a[j].length();
			if (i - len + 1 < 0) continue;
			ll s_hash = (string_hash(pre, i - len + 1, i));
			ll a_hash = (string_hash(prefix_hashes[j], 0, len - 1) * p_pow[i - len + 1]) % m;
			if (s_hash == a_hash) {
				if (len == (int) s.length()) dp[i] = 1;
				else dp[i] |= dp[i - len];
			}
		}
	}

//	for (int i = 0; i < (int) s.length(); i++) {
//		cout << dp[i] << " ";
//	}
//	cout << '\n';


	for (int i = 0; i < n; i++) {
		int len = a[i].length();
		for (int j = 1; j <= min(len, (int) s.length()); j++) {	
			ll s_hash = (string_hash(pre, (int) s.length() - j, (int) s.length() - 1)) % m;
			ll a_hash = (string_hash(prefix_hashes[i], 0, j - 1) * p_pow[(int) s.length() - j]) % m;
			
			if (s_hash == a_hash) {
				if (j == s.length()) dp[(int) s.length() - 1] = 1;
				else dp[(int) s.length() - 1] |= dp[(int) s.length() - 1 - j];
			}
		}
	}

	if (dp[(int) s.length() - 1]) cout << "YES\n";
	else cout << "NO\n";
	
	return 0;
}
