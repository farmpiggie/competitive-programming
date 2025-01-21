/*
 * separate into (even and odd indices)
 * pre[i][j] = # of values from 0...i that are < j.
 * mp[j] = map of {pre[i][j] - i / 2, cnt}
 * 
 * we know we have an answer if 
 * c[i][j] = pre[k][j] + (i - k) / 2
 * therefore we always search for c[i][j] - i / 2.
 * if it exists, add to answer.
 *
 *
 * what defines a good subarray?
 * can i redefine the answer?
 *
 * a subarray cannot have 
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		
		ll ans = 0;		
		for (int x = 1; x <= 10; x++) {
			vector<int> b(n);
			for (int i = 0; i < n; i++) {
				b[i] = (a[i] > x ? 1 : -1);
			}
			int sum = n;
			vector<int> pre(n);
			for (int i = 0; i < n; i++) {
				pre[i] = sum;
				sum += b[i];
			}
			vector<int> cnt(2 * n + 1);
			sum = n;
			int j = 0;
			for (int i = 0; i < n; i++) {
				if (a[i] == x) {
					while (j <= i) {
						cnt[pre[j]]++;
						j++;
					}
				}
				sum += b[i];
				ans += cnt[sum];
			}
		}
		ans = 1ll * n * (n + 1) / 2 - ans;
		cout << ans << '\n';
	}
}


