/*
 * assign composite values to each edge (can be negative)
 * arbitrarily root tree. distance of every node to root should be unique
 * max difference in distances is (2 * n - 1)
 */

#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define v2i vector<vi>

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        v2i adj(n);
        vector<array<int, 2>> edges;
        for (int i = 0; i < n - 1; i++) {
            int u, v; cin >> u >> v;
            --u; --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges.push_back({u, v});
        }

        v2i levels(n);
        vector<int> parent(n, 0);
        auto dfs = [&](this auto dfs, int node, int par = -1, int level = 0) -> void {
            parent[node] = par;
            levels[level].push_back(node);
            for (int nei : adj[node]) if (nei != par) dfs(nei, node, level + 1);
        };

        dfs(0);
        vi a(n, 0);
        int l = 2, r = 2 * n;
        for (int i = 0; i < levels.size(); i++) {
            for (int x : levels[i]) {
                if (i % 2) {
                    a[x] = r;
                    r -= 2;
                } else {
                    a[x] = l;
                    l += 2;
                }
            }
        }

        for (auto& [u, v] : edges) {
            if (abs(a[u] - a[v]) == 2) {
                if (parent[v] != u) swap(u, v); // u = par[v]
                a[v] = a[u] - 1;
            }
        }
        
        for (int x : a) cout << x << ' ';
        cout << '\n';


    }
    return 0;
}
