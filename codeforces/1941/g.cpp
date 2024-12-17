#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define f first
#define s second

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        map<int, int> mp;
        vector<vector<int>> adj(n + m);
        for (int i = 0; i < m; i++) {
            int u, v, c; cin >> u >> v >> c; --u; --v; --c;
            if (mp.find(c) == mp.end()) {
                mp[c] = n + (int) mp.size();
            }
            adj[u].push_back(mp[c]);
            adj[v].push_back(mp[c]);
            adj[mp[c]].push_back(u);
            adj[mp[c]].push_back(v);
        }

        int b, e; cin >> b >> e; --b; --e;
        queue<pii> q;
        vector<int> visited(n + m, 0);
        q.push({b, 0});
        int ans = 0;
        while (!q.empty()) {
            pii p = q.front(); q.pop();
            int node = p.f, len = p.s;
            if (visited[node]) continue;
            visited[node] = 1;

            if (node == e) {
                ans = len;
                break;
            }

            for (int nei : adj[node]) {
                q.push({nei, len + 1});
            }
        }
        cout << ans / 2 << '\n';
    }
    return 0;
}