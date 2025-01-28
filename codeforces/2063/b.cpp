#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, l, r; cin >> n >> l >> r;
		--l; --r;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		
		vector<int> left, right;
		for (int i = 0; i < l; i++) left.push_back(a[i]);
		for (int i = r + 1; i < n; i++) right.push_back(a[i]);
		sort(left.begin(), left.end());
		sort(right.begin(), right.end());

		vector<int> middle;
		ll sum = 0;
		for (int i = l; i <= r; i++) {
			middle.push_back(a[i]);
			sum += a[i];
		}
		sort(middle.begin(), middle.end());
		
		int j = middle.size() - 1, i = 0;
		ll cur = sum;
		while (i < left.size() && j >= 0) {
			if (left[i] < middle[j]) { // change the sum
				cur -= middle[j];
				cur += left[i];
				i++;
				j--;
			} else break;
		}

		ll ans = min(sum, cur);
		j = middle.size() - 1, i = 0;
		cur = sum;
		while (i < right.size() && j >= 0) {
			if (right[i] < middle[j]) {
				cur -= middle[j];
				cur += right[i];
				i++;
				j--;
			} else break;
		}

		ans = min(ans, cur);
	
		cout << ans << '\n';
	}
}
						   //
		// replace biggest values in middle with smallest values in left and right.
			
