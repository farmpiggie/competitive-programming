#include <bits/stdc++.h>
using namespace std;
 
/*
all bits need to be all 0 or 1s in order to cross
number for (x, y) = min(sum(0 bits) from a[0...x], b[0...y], sum(1 bits) from a[0...x], b[0....y])
how to calculate for sum(x, y)?
*/
 
 
#define vi vector<int>
#define v2i vector<vi>
#define v3i vector<v2i>
#define v4i vector<v3i>
 
#define ll long long
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<ll> a(n), b(n);
		for (int i = 0; i < n; i++) {
			char c; cin >> c;
			a[i] = (c - '0');
		}
		for (int i = 0; i < n; i++) {
			char c; cin >> c;
			b[i] = (c - '0');
		}
		vector<ll> sum(n, 0), ones_cnt(2 * n + 5, 0), zeros_cnt(2 * n + 5, 0), cnt(2 * n + 5, 0); // ones[diff between zeros and ones] = # of ones needed to deactivate
 
                int ones = 0, zeros = 0;
		for (int i = 0; i < n; i++) {
			if (b[i] == 1) ones++;
			else zeros++;
 
			// number of ones to deactivate
			ones_cnt[ones - zeros + n] += ones;
			cnt[ones - zeros + n]++;
			zeros_cnt[ones - zeros + n] += zeros;
		}
		for (int i = 2 * n - 3; i >= 0; i--) {
			zeros_cnt[i] += zeros_cnt[i + 1];
		}
 
		for (int i = 1; i < 2 * n + 5; i++) {
			ones_cnt[i] += ones_cnt[i - 1];
			cnt[i] += cnt[i - 1];
		}
 
		ll ans = 0;
		ones = 0, zeros = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == 1) ones++;
			else zeros++;
			// if diff is 2, we have 2 more zeros than ones
			// check how many values have -2 diff or less
			// if diff is -2, we have 2 more ones than zeros
			// check how many arrays of b have 2 more zeros than ones
			int diff = ones - zeros;
 
 
			ans += (ones * cnt[-diff + n] + (cnt[-diff + n] > 0 ? ones_cnt[-diff + n] : 0));
			ans += (zeros * (n - cnt[-diff + n]) + ((n - cnt[-diff + n] > 0 ? zeros_cnt[-diff + n + 1] : 0)));
		}
		cout << ans << '\n';
	}
}
 
 