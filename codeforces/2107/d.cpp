#include <bits/stdc++.h>
using namespace std;

struct diameter {
        int len, start, end, lca;

        bool operator<(const diameter& o) const {
                if (len != o.len) return len < o.len;
                if (start != o.start) return start < o.start;
                return end < o.end;
        }
};

int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while (t--) {
                int n; cin >> n;
                vector<vector<int>> adj(n);
                for (int i = 0; i < n - 1; i++) {
                        int u, v; cin >> u >> v;
                        --u; --v;
                        adj[u].push_back(v);
                        adj[v].push_back(u);
                }
                vector<bool> used(n, 0);

                vector<pair<int, int>> dp(n); // dp[i] = {len, node}
                vector<int> par(n);

                auto dfs = [&](this auto dfs, int u, int p = -1) -> diameter {
                        par[u] = p;
                        diameter ans = {0, 0, 0, 0};
                        if (used[u]) return ans;

                        vector<pair<int, int>> paths;
                        for (int v : adj[u]) if (!used[v] && v != p) {
                                diameter res = dfs(v, u);
                                ans = max(res, ans);
                                paths.push_back(dp[v]);
                        }
                        sort(paths.rbegin(), paths.rend());

                        if (paths.size() == 0) {
                                dp[u] = {1, u};
                                ans = {1, u, u, u};
                        } else {
                                dp[u] = {paths[0].first + 1, paths[0].second};
                                if (paths.size() == 1) {
                                        ans = max(ans, {paths[0].first + 1, max(u, paths[0].second), min(u, paths[0].second), u});
                                } else { // >= 2
                                        ans = max(ans, {paths[0].first + paths[1].first + 1, max(paths[0].second, paths[1].second), min(paths[0].second, paths[1].second), u});
                                }
                        }
                        return ans;
                };

                priority_queue<diameter> pq;
                pq.push(dfs(0));
                while (!pq.empty()) {
                        diameter cur = pq.top(); pq.pop();
                        if (cur.len == 0) continue;
                        cout << cur.len << " " << cur.start + 1 << " " << cur.end + 1 << " ";
                        vector<int> path = {cur.lca};
                        int u = cur.start;
                        while (u != cur.lca) {
                                path.push_back(u);
                                u = par[u];
                        }
                        u = cur.end;
                        while (u != cur.lca) {
                                path.push_back(u);
                                u = par[u];
                        }
                        for (int node : path) {
                                used[node] = 1;
                        }
                        for (int node : path) {
                                for (int v : adj[node]) {
                                        if (!used[v]) {
                                                diameter nxt = dfs(v, node); // should be at least length 1
                                                pq.push(nxt);
                                        }
                                }
                        }
                }
                cout << '\n';
        }
}









