#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;

int main() {
	vector<ll> pow2(MAXN, 0), sum(MAXN, 0);
	pow2[0] = 1;
	sum[0] = 0;
	for (int i = 1; i <= MAXN; i++) {
		pow2[i] = (pow2[i - 1] * 2) % MOD;
	}


	int t; cin >> t;
	vector<int> n(t), k(t);
	for (int& x : n) cin >> x;
	for (int& x : k) cin >> x;

	for (int i = 0; i < t; i++) {
		if (k[i] == 0 || k[i] == n[i]) cout << "1\n";
		else cout << pow2[k[i]] << '\n';
	}

	return 0;
}