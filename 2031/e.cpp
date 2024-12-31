#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<vector<int>> adj(n, vector<int>(0));
		for (int i = 1; i < n; i++) {
			int x; cin >> x;
			adj[x - 1].push_back(i);
		}

		auto dfs = [&](this auto dfs, int node) -> int {
			if (adj[node].size() == 0) return 0;
			map<int, int> mp;
			priority_queue<int, vector<int>, greater<int>> pq;
			for (int nei : adj[node]) {
				pq.push(dfs(nei));
			}
			bool bad = adj[node].size() == 1; // has remainder
			while (pq.size() > 1) {
				int x = pq.top(); pq.pop();
				int y = pq.top(); 
				if (x == y) {
					pq.pop();
					pq.push(x + 1);
				} else { // x < y
					bad = true;
				}
			}

//            cout << "size of node " << node + 1 << " is: " << pq.top() + bad << '\n';
			return pq.top() + bad;
		};

		cout << dfs(0) << '\n';
	}
	return 0;
}


