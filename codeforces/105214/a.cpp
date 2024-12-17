#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vl vector<ll> 
#define v2l vector<vl>

const int MOD = 1e9 + 7;

ll binpow(int a, int b) {
	if (b == 0) return 1;
	ll half = binpow(a, b / 2);
	if (b % 2) return (half * half * a) % MOD;
	else return (half * half) % MOD;
}

// modular inverse
ll inv(ll a) {
	return binpow(a, MOD - 2);
}


int main() {
	string s; cin >> s;

	int chunks = 0;
	for (int i = 0; i < (int) s.size() - 4; i++) {
		string s2 = s.substr(i, 4);
		if (s2 == "ABCD" || s2 == "BCDA" || s2 == "CDAB" || s2 == "DABC") {
			chunks++;
			i += 3;
		}
	}
	
	int rem = (int) s.size() - chunks * 4;

	// blocks[i] = # of canonical ways to create a block of size 4 * i.
	// we can break each block into w (block) x (block) y (block) z
	// dp1[i][j] = # of canonical ways we can create i blocks with total siz 4 * j.
	// dp1[i][j] = sum(dp[i - 1][j - k] * block[k]) for 1 <= k <= j // does not enforce a position on k.
	// blocks[i] = (3 choose k) * binpow(3, k) * dp1[k][i - 1] + blocks[i - l] * blocks[l]
	// 				either we choose to interleave, or we simply add another block to the back of blocks[i - 1]
	return 0;
}
