#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

typedef pair<int, int> pii;

int t, n;

auto cmp = [](const pii& a, const pii& b) {
	return (a.first - a.second < b.first - b.second); // if there are more unpairable nodes, it should appear first
};

pii dp(int i, vector<vector<int>>& adj) {
	if (adj[i].size() == 0) return {1, 0};
	vector<pii> arr;
	int total = 1;
	int num_paired = 0;
	for (int child : adj[i]) {
		pii p = dp(child, adj);
		total += p.first;
		num_paired += p.second;
		arr.push_back(p);
	}

	priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp, arr);
	vector<pii> arr2;
	while (pq.size() > 1) {
		pii p1 = pq.top(); pq.pop();
		pii p2 = pq.top(); pq.pop();
		int gap1 = p1.first - p1.second;
		int gap2 = p2.first - p2.second; // gap1 >= gap2 for sure
		//gap1 -= gap2;

		// paired
		num_paired += 2 * gap2;
		p1.second += gap2;
		// 
		p2.first -= gap2;
		if (p1.first != p1.second) {
			pq.push(p1);
		} else {
			arr2.push_back(p1);
		}
		arr2.push_back(p2);
	}	
	if (pq.size() == 1) { // unpaired nodes. note that the number of paired nodes for other subtrees should be even
		pii p = pq.top(); pq.pop();
		// cout << "unpaired: " << p.first << " " << p.second << '\n';
		for (pii p2 : arr2) {
			// cout << "matching with: " << p2.first << " " << p2.second << '\n';
			int gap = p.first - p.second;
			if (gap <= 1) break;
			
			int new_pair = min(gap / 2, p2.second / 2) * 2; // truncate odd gap if gap is odd
			p.first -= new_pair;
			// cout << "new pair: " << new_pair << '\n';
			num_paired += new_pair;
			
		}
	}
	// cout << "subtotal for node: " << i << " is: " << total << ", " << num_paired << '\n';
	return make_pair(total, num_paired);
}

void solve() {
	cin >> n;
	vector<vector<int>> adj = vector<vector<int>>(n + 1, vector<int>(0));
	for (int i = 2; i <= n; i++) {
		int p; cin >> p;
		adj[p].push_back(i);
	}
	cout << dp(1, adj).second / 2 << '\n';
}

int main() {
	cin >> t;
	while (t--) solve();
	return 0;
}