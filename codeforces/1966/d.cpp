// EDITORIAL:
// with no restrictions, we can add from 1 to 10^6
// 1, 2, 4, 8, ... 2 ^ 19
// let i be largest integer such that 2^i <= k. if we remove 2^i, then we won't be able to make k.
// 1, 2, 4, ..., 2^(i - 1), 2^(i + 1), ...., 2 ^ 19
// how can we make the rest of the numbers?
// we need to deal with numbers between 2^i and (k - 1), (k + 1) to 2^(i + 1) - 1
// deal with the first range by adding in k - 2 ^ i
// we need k + 1 (otherwise we can't solve, adding a smaller number to make k + 1 messes it up, and we can't make it with the previous values
// thus we can resort to evaluating v - k - 1 + (k + 1), and in the case where v - k - 1 has 2^i bit set, we can have a (k + 1 + 2^i) instead
#include <bits/stdc++.h>
using namespace std;



int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		int x = log2(k);
		cout << 22 << '\n';
		vector<int> ans;
		for (int i = 0; i < 20; i++) {
			if (i == x) continue;
			ans.push_back((1 << i));
		}
		ans.push_back(k - (1 << x));
		ans.push_back(k + 1);
		ans.push_back(k + 1 + (1 << x));
		for (int& x : ans) cout << x << " ";
		cout << '\n';
	}
}
