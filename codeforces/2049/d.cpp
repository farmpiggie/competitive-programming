/*
 * f(i, j) = min cost to reach i, j.
 * g(i, j, x) = min cost to reach i, j given row i has been shifted x times.
 *
 * g(i, j, x) = kx + min(f(i - 1, l) + sum(a[i][l + 1 - x], a[i][j - x]) over all l.
 * f(i, j) = min(g(i, j, x)) over all x
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define v2i vector<vi>
#define vl vector<ll>
#define v2l vector<vl>
#define v3l vector<v2l>
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;

		v2i a(n, vi(m));
		for (auto& b : a) 
			for (int& c : b) 
				cin >> c;

		v2l f(n + 1, vl(m, 1e18));	
		
		// init	
		f[0][0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int x = 0; x < m; x++) {
				vl tmp(m, 1e18);
				for (int j = 0; j < m; j++) {
					tmp[j] = f[i - 1][j] + a[i - 1][(j + x) % m] + 1ll * k * x;
				}
				/*for (int j = 0; j < m; j++) {
					tmp[j] = min(tmp[j], tmp[(j + m - 1) % m] + a[i - 1][(j + x) % m]);
				}*/
				for (int j = 0; j < m; j++) {
					tmp[j] = min(tmp[j], tmp[(j + m - 1) % m] + a[i - 1][(j + x) % m]);
				}
				for (int j = 0; j < m; j++) f[i][j] = min(f[i][j], tmp[j]);
			}
		}
		cout << f[n][m - 1] << '\n';
	}
}
