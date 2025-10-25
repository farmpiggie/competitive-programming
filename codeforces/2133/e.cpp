#include <bits/stdc++.h>
using namespace std;

struct dsu {
    int n;
    vector<int> sz, par;
    vector<vector<pair<int, int>>> edges;

    dsu(int _n) {
        n = _n;
        sz.assign(n, 1);
        par.resize(n);
        edges.assign(n, {});
        iota(par.begin(), par.end(), 0);
    }

    int find(int x) {
        if (par[x] == x)
            return x;
        else
            return par[x] = find(par[x]);
    }

    void merge(int x, int y) {
        int orig_x = x, orig_y = y;
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (sz[x] < sz[y])
            swap(x, y);
        par[y] = x;
        sz[x] += sz[y];
        for (auto edge : edges[y])
            edges[x].push_back(edge);
        edges[x].push_back({orig_x, orig_y});
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        set<int> removed;
        auto dfs = [&](this auto dfs, int u, int p = -1) -> int {
            int sum = 1;
            for (int v : adj[u])
                if (v != p)
                    sum += dfs(v, u);
            if (sum >= 4) {
                removed.insert(u);
                sum = 0;
            }
            return sum;
        };

        dfs(0);

        assert((int)removed.size() <= n / 4);

        vector<int> ans;

        dsu uf(n);
        for (int u = 0; u < n; u++) {
            if (removed.count(u))
                continue;
            for (int v : adj[u]) {
                if (removed.count(v))
                    continue;
                uf.merge(u, v);
            }
        }

        set<int> ccs;
        for (int u = 0; u < n; u++) {
            int cc = uf.find(u);
            if (ccs.count(cc))
                continue;
            ccs.insert(cc);
            vector<pair<int, int>> edges = uf.edges[cc];
            /*
            cout << "edges: \n";
            for (auto [x, y] : edges) {
                cout << x + 1 << " " << y + 1 << '\n';
            }
            */
            if (edges.size() == 0) {
                ans.push_back(u); // doesnt matter since its alone
            } else if (edges.size() == 1) {
                ans.push_back(edges[0].first);
                ans.push_back(edges[0].second);
            } else { // edges.size() == 2
                map<int, int> mp;
                set<int> s;
                for (auto [u, v] : edges) {
                    mp[u]++;
                    mp[v]++;
                    s.insert(u);
                    s.insert(v);
                }
                int middle = -1, left = -1, right = -1;
                for (int u : s) {
                    if (mp[u] == 2)
                        middle = u;
                    else if (left == -1)
                        left = u;
                    else
                        right = u;
                }
                ans.push_back(left);
                ans.push_back(middle);
                ans.push_back(right);
            }
        }

        cout << n + (int)removed.size() << '\n';
        for (int u : removed) {
            cout << "2 " << u + 1 << '\n';
        }
        for (int u : ans) {
            cout << "1 " << u + 1 << '\n';
        }
    }
}