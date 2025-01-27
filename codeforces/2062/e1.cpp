/*
 * idea: we can win if we take the largest node (in weight) i s.t. if we remove subtree rooted at i, there exists a node j s.t. w[j] > w[i] and j is not in the subtree of i.
 * therefore, we take i, our opponent takes j, and we win.
 * use small to large merging (or pre/post order traversal array) to check if every node contains some node larger outside its subtree.
 * we will take the one with biggest weight.
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<vector<int>> adj(n);
		vector<int> w(n);
		set<int> unique;
		for (int& x : w) {
			cin >> x;
			unique.insert(x);
		}
		map<int, int> compress;
		int w_max = 0;
		for (int x : unique) {
			compress[x] = w_max++;
		}
		vector<int> tot(w_max);
		for (int i = 0; i < n; i++) {
			w[i] = compress[w[i]];
			tot[w[i]]++;
		}
		
		for (int i = 0; i < n - 1; i++) {
			int u, v; cin >> u >> v;
			--u; --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		vector<int> works(w_max, -1);
		vector<map<int, int>> cnt(n);

		auto dfs = [&](this auto dfs, int node, int par = -1) -> void {
			cnt[node][w[node]]++;
			for (int nei : adj[node]) if (nei != par) {
				dfs(nei, node);
				if (cnt[nei].size() > cnt[node].size()) {
					cnt[node].swap(cnt[nei]);
				}
				for (auto [val, count] : cnt[nei]) {
					cnt[node][val] += count;
				}
			}
			if (cnt[node][w[node] + 1] < tot[w[node] + 1]) {
				works[w[node]] = node;
			}
		};

		dfs(0);

		int ans = -1;
		for (int i = w_max - 2; i >= 0; i--) {
			if (works[i] != -1) {
				ans = works[i];
				break;
			}
		}

		cout << ans + 1 << '\n';




	}
}


		
