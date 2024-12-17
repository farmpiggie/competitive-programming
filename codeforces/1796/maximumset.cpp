#include <bits/stdc++.h>
using namespace std;

void solve() {
	int l, r; cin >> l >> r;

	int left = 0, right = 20; 
	int len = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		int val = l * (1 << mid);
		if (val > r) {
			right = mid - 1;
		} else {
			left = mid + 1;
			len = max(len, mid);
		}
	}
	len++; // length of the maximal subarray
	// end values can range from (left * (1 << (len - 1)) to r) at the greatest
	// grab psum[r] - psum[left * (1 << (len - 1) - 1] for sum at this range



}

int main() {
	ios_base::sync_with_stdio(0);
  	cin.tie(0);
  	int t; cin >> t;

  	

  	while (t--) solve();

	return 0;
}