#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int &x : a) cin >> x;
		
		vector<vector<int>> adj(n);
		vector<int> indegree(n, 0), ans(n);
		int step = 1;
		vector<int> b(n);
		iota(b.begin(), b.end(), 0);
		while (b.size() > 1) { 
			vector<int> c;
			int i2 = 0;
			for (;i2 < b.size(); i2++) {
				int u = b[i2];
				if (a[u] != step) break;
				if (i2 < b.size() - 1) {
					int r = b[i2 + 1];
					if (a[r] == step) {
						if (step & 1) {
							adj[u].push_back(r);
							indegree[r]++;
						} else {
							adj[r].push_back(u);
							indegree[u]++;
						}
					}
				}
			}
			int j = b.size() - 1;
			for (; j >= 0; j--) {
				int u = b[j];
				if (a[u] != step) break;
				if (j > 0) {
					int l = b[j - 1];
					if (a[l] == step) {
						if (step & 1) {
							adj[u].push_back(l);
							indegree[l]++;
						} else {
							adj[l].push_back(u);
							indegree[u]++;
						}
					}
				}
			}
			for (int i = i2; i < j + 1; i++) {
				int u = b[i];
				if (a[u] != step) {
					c.push_back(u);
					if (i > 0) {
						int l = b[i - 1];
						if (step & 1) { // local minima 
							adj[l].push_back(u);
							indegree[u]++;
						}  else {
							adj[u].push_back(l);
							indegree[l]++;
						}
					}
					if (i < b.size() - 1) {
						int r = b[i + 1];
						if (step & 1) {
							adj[r].push_back(u);
							indegree[u]++;
						} else {
							adj[u].push_back(r);
							indegree[r]++;
						}
					}
				} else { // a[u] == step
					if (i == b.size() - 1) continue;
					int r = b[i + 1];
					// not sure if this even matters
					if (a[r] == step) {
						if (step & 1) {
							adj[r].push_back(u);
							indegree[u]++;
						} else {
							adj[u].push_back(r);
							indegree[r]++;
						}
					}
				}
			}
			// cout << "size of c: " << c.size() << endl;
			b = c;
			step++;
		}
		
		// for (int u = 0; u < n; u++) {
		// 	for (int v : adj[u]) {
		// 		cout << '(' << u << ", " << v << ')' << endl;
		// 	}
		// }

		queue<int> q;
		for (int i = 0; i < n; i++) if (indegree[i] == 0) q.push(i);
		
		// cout << q.size() << '\n';

		int val = n;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			ans[u] = val--;
			for (int v : adj[u]) {
				indegree[v]--;
				if (indegree[v] == 0) q.push(v);
			}
		}

		for (int x : ans) cout << x << ' ';
		cout << '\n';
	}
}


					


						


