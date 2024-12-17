// prefix sums to count time to reach each point
// binary search on point, then calculate distance along the path
// calculate speed for each of k segments
#include <bits/stdc++.h>
using namespace std;

int bin_search(int d, vector<int>& a) {
	int n = (int) a.size();
	int best = 0;
	int lo = 0, hi = n - 1;
	while (lo <= hi) {
		int mi = lo + (hi - lo) / 2;
		if (a[mi] <= d) {
			best = max(best, mi);
			lo = mi + 1;
		} else {
			hi = mi - 1;
		}
	}
	return best;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n, k, q; cin >> n >> k >> q;
		vector<int> a(k + 1, 0), b(k + 1, 0);
		for (int i = 1; i <= k; i++) cin >> a[i];
		for (int i = 1; i <= k; i++) cin >> b[i];
		vector<int> dist(k + 1), time(k + 1);
		for (int i = 0; i < k; i++) {
			dist[i] = a[i + 1] - a[i];
			time[i] = b[i + 1] - b[i];
		}
		dist[k] = 1;
		time[k] = 0;
		while (q--) {
			int d; cin >> d;
			int idx = bin_search(d, a);
			cout << b[idx] + 1ll * (d - a[idx]) * time[idx] / dist[idx] << ' '; 
		}
		cout << '\n';
	}
	return 0;
}
