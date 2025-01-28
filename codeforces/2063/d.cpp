/*
 * k_max = floor((a + b) / 3)
 *
 * if k = 1, f(k) = max(a[n] - a[1]), (b[n] - b[1]))
 *
 *
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<int> a(n), b(m);
		for (int& x : a) cin >> x;
		for (int& x : b) cin >> x;
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		int k_max = min((n + m) / 3, min(n, m));
		cout << k_max << '\n';
		vector<int> top, bottom; // top is a, bottom is b
		for (int i = 0; i < n / 2; i++) {
			top.push_back(a[n - 1 - i] - a[i]);
		}
		for (int i = 0; i < m / 2; i++) {
			bottom.push_back(b[m - 1 - i] - b[i]);
		}
	
		int i = 0, j = 0;	
		int a_left = n, b_left = m;
		ll ans = 0;
		for (int _ = 0; _ < k_max; _++) {
			if (a_left >= 2 && b_left >= 2) { // we can pick whatever we'd like
				if (top[i] > bottom[j]) {
					a_left -= 2;
					b_left--;
					ans += top[i];
					i++;
				} else {
					b_left -= 2;
					a_left--;
					ans += bottom[j];
					j++;
				}
			} else if (a_left >= 2) { // b_left <= 1
				if (b_left == 0) { // we must remove one b, and add two a.
					j--;
					ans -= bottom[j];
					b_left += 2;
					a_left++;
					
					ans += top[i];
					i++;
					ans += top[i];
					i++;
					a_left -= 4;
					b_left -= 2;
				} else { // b_left == 1, so we just need to use one.
					ans += top[i];
					i++;
					a_left -= 2;
					b_left--;
				}
			} else { 
				if (a_left == 0) {
					i--;
					ans -= top[i];
					a_left += 2;
					b_left++;

					ans += bottom[j];
					j++;
					ans += bottom[j];
					j++;
					b_left -= 4;
					a_left -= 2;
				} else {
					ans += bottom[j];
					j++;
					b_left -= 2;
					a_left--;
				}
			}
			cout << ans << ' ';

		}
		cout << '\n';
	}
}
