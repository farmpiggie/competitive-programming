#include <bits/stdc++.h>
using namespace std;

#define ll long long

void print_pq(priority_queue<ll>& pq) {
	cout << "pq: ";
	vector<ll> arr;
	while (!pq.empty()) {
		arr.push_back(pq.top());
		pq.pop();
	}
	for (ll x : arr) {
		cout << x << " ";
		pq.push(x);
	}
	cout << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, q; cin >> n >> q;
		vector<ll> a(n);
		ll all_or = 0;
		for (ll &x : a) {
			cin >> x;
			all_or |= x;
		}

		vector<ll> ans(32, LLONG_MAX); // cost to set x bits 
		ans[__builtin_popcount(all_or)] = 0;
		for (int i = 0; i < 31; i++) { // most is 30th LSB (starting from 0)
			vector<ll> b;
			for (ll x : a) b.push_back(x);
			ll cost = 0;
			for (int j = i; j >= 0; j--) {
				int mx_index = 0;
				for (int k = 0; k < n; k++) {
					b[k] = b[k] % (1ll << (j + 1));
					if (b[k] > b[mx_index]) {
						mx_index = k;
					}
				}
				// biggest number could be between [1 << j] and [1 << (j + 1) - 1]
				// how much to set jth bit?

				if (!((b[mx_index] >> j) & 1)) { // jth bit is not already set by some number
					assert((1ll << j) - b[mx_index] >= 0);
					cost += (1ll << j) - b[mx_index];
					b[mx_index] = (1ll << j);
				}
			} 
			int set = __builtin_popcount(all_or >> (i + 1)) + i + 1;
			assert(set <= 31);
			ans[set] = min(ans[set], cost);
		}

		for (int i = 30; i >= 0; i--) {
			ans[i] = min(ans[i], ans[i + 1]);
		}

		while (q--) {
			int x; cin >> x;
			int index = upper_bound(ans.begin(), ans.end(), x) - ans.begin(); // smallest index s.t. ans[x] > arr
			cout << max(0, index - 1) << '\n';
		}
	}
}
