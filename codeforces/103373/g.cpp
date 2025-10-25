#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define f first
#define s second
#define ll long long

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<vector<pii>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c; cin >> a >> b >> c;
        --a; --b;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    for (int i = 0; i < n; i++) sort(adj[i].begin(), adj[i].end(), [](const pii& a, const pii& b) {
        return a.second < b.second;
    });

    // dpl[i] = # of paths ending at edge from (par[i], i)
    vector<ll> dpl(n, 0), dpr(n, 0), p(n, -1);

    auto dfs1 = [&](auto&& self, int node, int par = -1, int weight = (int) 1e9 + 5) -> void {
        p[node] = par;
        for (const pii& edge : adj[node]) if (edge.first != par) self(self, edge.first, node, edge.second);
        
        // monotonically increasing
        for (const pii& edge : adj[node]) if (edge.second < weight) dpl[node] += dpl[edge.first];

        dpl[node]++;
    };

    auto dfs2 = [&](auto&& self, int node, int par = -1, int weight = (int) 0) -> void {
        for (const pii& edge : adj[node]) if (edge.first != par) self(self, edge.first, node, edge.second);

        // monotonically decreasing
        for (const pii& edge : adj[node]) if (edge.second > weight) dpr[node] += dpr[edge.first];

        dpr[node]++;
    };

    dfs1(dfs1, 0);
    dfs2(dfs2, 0);

    // for (int i = 0; i < n; i++) {
    //     cout << dpl[i] << " ";
    // }
    // cout << endl;

    ll ans = 0; // double count edges
    for (int i = 1; i < n; i++) {
        ans += dpl[i] + dpr[i];
    }  

    // cout << ans << endl;

    for (int i = 0; i < n; i++) {
        if (adj[i].size() == 1) continue; // leaf node
        ll cnt = 0;
        for (int j = 0; j < adj[i].size(); j++) if (adj[i][j].first != p[i]) cnt += dpr[adj[i][j].first];
        int k = 0;
        for (int j = 0; j < adj[i].size(); j++) {
            if (adj[i][j].first == p[i]) continue;
            while (k < adj[i].size() && adj[i][k].second <= adj[i][j].second) {
                if (adj[i][k].first != p[i]) cnt -= dpr[adj[i][k].first];
                k++;
            }
            ans += dpl[adj[i][j].first] * cnt; // cnt = sum(dpr[adj[k]].first) s.t. w(node, k) > w(node, adj[j].first)
        }
    }

    cout << ans << endl;

    return 0;
}