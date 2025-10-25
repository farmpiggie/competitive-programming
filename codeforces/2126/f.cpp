#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define f first
#define s second

int main() {
//        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n, q; cin >> n >> q;
                vector<int> a(n);
                for (int &x : a) cin >> x;
                vector<vector<pii>> adj(n); 
                ll tot = 0;
                for (int i = 0; i < n - 1; i++) {
                        int u, v, w; cin >> u >> v >> w;
                        --u; --v;
                        adj[u].push_back({v, w});
                        adj[v].push_back({u, w});
                        tot += w;
                }

                vector<int> cost(n), par(n); // cost[u] = weight of edge from par[u] to u

                auto dfs = [&](this auto dfs, int u, int p = -1, int w = 0) -> void {
                        par[u] = p;
                        if (p != -1) cost[u] = w;
                        for (auto &[v, nxt_w] : adj[u]) if (v != p) dfs(v, u, nxt_w);
                };

                dfs(0);

                vector<map<int, ll>> mp(n); // mp[node][color] = sum(edges with children of said color)
                auto dfs2 = [&](this auto dfs2, int u, int p = -1) -> void {
                        for (auto &[v, _] : adj[u]) if (v != p) {
                                dfs2(v, u);
                                mp[u][a[v]] += cost[v];
                                if (a[u] == a[v]) tot -= cost[v];
                        }
                };

                dfs2(0);

                while (q--) {
                        int v, x; cin >> v >> x;
                        --v;
                        if (mp[v].find(x) != mp[v].end()) { 
                                tot -= mp[v][x]; // matches with children of color x
                        }
                        if (mp[v].find(a[v]) != mp[v].end()) {
                                tot += mp[v][a[v]]; // no longer matches with children of color a[v]
                        }
                        // update parent
                        if (par[v] != -1) {
                                mp[par[v]][a[v]] -= cost[v];
                                if (a[par[v]] == a[v]) {
                                        tot += cost[v];
                                }
                                if (mp[par[v]][a[v]] == 0) mp[par[v]].erase(a[v]);

                                mp[par[v]][x] += cost[v];
                                if (a[par[v]] == x) {
                                        tot -= cost[v];
                                }
                        }
                        a[v] = x;
                        cout << tot << '\n';
                }
        }
}









