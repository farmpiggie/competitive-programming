#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define v2i vector<vi>

const int MAXDIFF = 505 * 100;
const int MAXN = 51;

int main() {
  	int n, m; 
	cin >> n >> m;
	//n = 50, m = 50;
	v2i a(n, vi(m, 0));
	//v2i a(n, vi(m, 1));
	for (auto& x : a) for (int& y : x) cin >> y;
	
	int ans = 0;
	vector<map<int, int>> b(m); // changes per column
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			b[j][a[i][j] - a[i][(j + 1) % m]]++;
		}
	}


	// dp1[col][sum] = max cnt
	v2i dp1(m + 1, vi(MAXDIFF, INT_MIN));
	dp1[0][MAXDIFF / 2] = 0;
	for (int j = 1; j <= m; j++) {
		for (int k = 0; k < MAXDIFF; k++) {
			for (auto& [key, value] : b[j - 1]) {
				if (k - key >= 0 && k - key < MAXDIFF) {
	//				if (j == 3 && k == MAXDIFF / 2 + 500) {
	//					cout << "k and key: " << k << " " << key << '\n';
	//					cout << "comes from dp1[" << j - 1 << "][" << k - key << "]\n";
	//				}
					dp1[j][k] = max(dp1[j][k], dp1[j - 1][k - key] + value);
				}
			}
		}
	}
	// consider value equals zero.
	int mn = INT_MAX;
	int sum = 0;
	for (int j = 0; j < m; j++) {
		int big = 0;
		for (auto& [key, value] : b[j]) {
			big = max(big, value);
		}
		sum += big;
		mn = min(mn, big);
	}
	ans += max(sum - mn, dp1[m][MAXDIFF / 2]);

	vector<map<int, int>> c(n);
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			c[i][a[i][j] - a[(i + 1) % n][j]]++;
		}
	}

	v2i dp2(n + 1, vi(MAXDIFF, INT_MIN));
	dp2[0][MAXDIFF / 2] = 0;
	for (int i = 1; i <= n; i++) {
		for (int k = 0; k < MAXDIFF; k++) {
			for (auto& [key, value] : c[i - 1]) {
				if (k - key >= 0 && k - key < MAXDIFF) dp2[i][k] = max(dp2[i][k], dp2[i - 1][k - key] + value);
			}
		}
	}

	mn = INT_MAX;
	sum = 0;
	for (int i = 0; i < n; i++) {
		int big = 0;
		for (auto& [_, value] : c[i]) {
			big = max(big, value);
		}
		sum += big;
		mn = min(mn, big);
	}
	ans += max(sum - mn, dp2[n][MAXDIFF / 2]);
	// cout << dp1[m][MAXDIFF / 2] << " " << dp2[n][MAXDIFF / 2] << '\n';
	cout << ans << '\n';
    return 0;
}
