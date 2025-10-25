#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 998244353;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;

	vector<int> f(n + 1, 0);
	f[1] = 1;
	f[2] = 1;
	for (int i = 3; i <= n; i++) {
		int x = i - f[i - 1];
		int y = i - f[i - 2];
		f[i] = ((x > 2 ? f[x] : 1) + (y > 2 ? f[y] : 1)) % MOD;
	}
	
	cout << f[n] << '\n';
}

