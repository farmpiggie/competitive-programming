#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct dsu {
    int n;
    vector<int> par, sz;

    dsu(int _n) {
        n = _n;
        sz.assign(n, 1);
        par.resize(n);
        iota(par.begin(), par.end(), 0);
    }

    int find(int x) {
        if (par[x] == x)
            return x;
        else
            return par[x] = find(par[x]);
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (sz[x] < sz[y])
            swap(x, y);
        sz[x] += sz[y];
        par[y] = x;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n);
        vector<pair<int, int>> edges;
        map<pair<int, int>, int> edge_to_index;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges.push_back({min(u, v), max(u, v)});
            edge_to_index[{min(u, v), max(u, v)}] = i;
        }

        set<pair<int, int>> bridges;

        vector<bool> visited(n, 0);
        vector<int> tin(n, -1), low(n, -1);
        int timer = 0;

        auto dfs = [&](this auto dfs, int u, int p = -1) -> void {
            visited[u] = 1;
            tin[u] = low[u] = timer++;
            bool parent_skipped = false;
            for (int v : adj[u]) {
                if (v == p && !parent_skipped) {
                    parent_skipped = true;
                    continue;
                }
                if (visited[v]) {
                    low[u] = min(low[u], tin[v]);
                } else {
                    dfs(v, u);
                    low[u] = min(low[u], low[v]);
                    if (low[v] > tin[u]) {
                        bridges.insert({min(u, v), max(u, v)});
                    }
                }
            }
        };

        dfs(0);

        dsu uf(n);
        for (auto &p : edges) {
            if (bridges.find(p) != bridges.end())
                continue;

            uf.merge(p.first, p.second);
        }

        bool no_bridge = uf.find(0) == uf.find(n - 1);

        vector<int> dist(n, INF); // distance from a bridge
        vector<int> ans(n);
        vector<pair<int, int>> bridge_list(bridges.begin(), bridges.end());
        if (!no_bridge) {
            // condense the graph
            map<int, vector<pair<int, int>>> adj2;
            for (auto [x, y] : bridge_list) {

                int nx = uf.find(x);
                int ny = uf.find(y);
                adj2[nx].push_back({ny, edge_to_index[{min(x, y), max(x, y)}]});
                adj2[ny].push_back({nx, edge_to_index[{min(x, y), max(x, y)}]});
            }

            int start = uf.find(0);
            int end = uf.find(n - 1);

            vector<int> cur;
            vector<int> required;

            auto dfs2 = [&](this auto dfs2, int u, int p = -1) {
                if (u == end) {
                    required = cur;
                    return;
                }
                for (auto [v, i] : adj2[u])
                    if (v != p) {
                        cur.push_back(i);
                        dfs2(v, u);
                        cur.pop_back();
                    }
            };

            dfs2(start);

            queue<array<int, 3>> q; // node, dist, edge
            set<pair<int, int>> start_nodes;
            sort(required.begin(), required.end()); // edge indices first?
            for (int i : required) {
                start_nodes.insert({edges[i].first, i});
                start_nodes.insert({edges[i].second, i});
            }

            for (auto [u, i] : start_nodes) {
                q.push({u, 0, i});
            }

            while (!q.empty()) {
                auto [u, d, i] = q.front();
                q.pop();
                if (dist[u] == d && i < ans[u]) {
                        ans[u] = i;
                        continue;
                }
                if (dist[u] != INF)
                    continue;
                dist[u] = d;
                ans[u] = i;
                for (auto v : adj[u])
                    q.push({v, d + 1, i});
            }
        }

        int q;
        cin >> q;
        while (q--) {
            int c;
            cin >> c;
            --c;
            cout << (no_bridge ? -1 : ans[c] + 1) << ' ';
        }
        cout << '\n';
    }
}